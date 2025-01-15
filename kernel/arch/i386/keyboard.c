#include <kernel/system.h>
#include <kernel/serial_com.h>

bool shift = false;
bool caps_lock = false;
bool alt = false;
bool ctrl = false;
bool kbd_disable = false;
uint kbd_inp_buf_index = 0;

bool write_to_input_buffer = false;
uchar input_buffer[128] = {};
uchar last_key = '\0';

/* KBDUS means US Keyboard Layout. This is a scancode table
*  used to layout a standard US keyboard. I have left some
*  comments in to give you an idea of what key is what, even
*  though I set it's array index to 0. You can change that to
*  whatever you want using a macro, if you wish! */
unsigned char kbdus_lower[128] =
{
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8',	/* 9 */
  '9', '0', '-', '=', '\b',	/* Backspace */
  '\t',			/* Tab */
  'q', 'w', 'e', 'r',	/* 19 */
  't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',		/* Enter key */
    0,			/* 29   - Control */
  'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',	/* 39 */
 '\'', '`',   0,		/* Left shift */
 '\\', 'z', 'x', 'c', 'v', 'b', 'n',			/* 49 */
  'm', ',', '.', '/',   0,					/* Right shift */
  '*',
    0,	/* Alt */
  ' ',	/* Space bar */
    0,	/* Caps lock */
    0,	/* 59 - F1 key ... > */
    0,   0,   0,   0,   0,   0,   0,   0,
    0,	/* < ... F10 */
    0,	/* 69 - Num lock*/
    0,	/* Scroll Lock */
    0,	/* Home key */
    0,	/* Up Arrow */
    0,	/* Page Up */
  '-',
    0,	/* Left Arrow */
    0,
    0,	/* Right Arrow */
  '+',
    0,	/* 79 - End key*/
    0,	/* Down Arrow */
    0,	/* Page Down */
    0,	/* Insert Key */
    0,	/* Delete Key */
    0,   0,   0,
    0,	/* F11 Key */
    0,	/* F12 Key */
    0,	/* All other keys are undefined */
};

unsigned char kbdus_upper[128] =
{
    0,  27, '!', '@', '#', '$', '%', '^', '&', '*', /* 9 */
  '(', ')', '_', '+', '\b', /* Backspace */
  '\t',         /* Tab */
  'Q', 'W', 'E', 'R',   /* 19 */
  'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', '\n',     /* ENTER KEY */
    0,          /* 29   - CONTROL */
  'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', /* 39 */
 '\"', '~',   0,        /* LEFT SHIFT */
 '\\', 'Z', 'X', 'C', 'V', 'B', 'N',            /* 49 */
  'M', '<', '>', '?',   0,                  /* RIGHT SHIFT */
  '*',
    0,  /* Alt */
  ' ',  /* Space bar */
    0,  /* Caps lock */
    0,  /* 59 - F1 key ... > */
    0,   0,   0,   0,   0,   0,   0,   0,
    0,  /* < ... F10 */
    0,  /* 69 - Num lock*/
    0,  /* Scroll Lock */
    0,  /* Home key */
    0,  /* Up Arrow */
    0,  /* Page Up */
  '_',
    0,  /* Left Arrow */
    0,
    0,  /* Right Arrow */
  '+',
    0,  /* 79 - End key*/
    0,  /* Down Arrow */
    0,  /* Page Down */
    0,  /* Insert Key */
    0,  /* Delete Key */
    0,   0,   0,
    0,  /* F11 Key */
    0,  /* F12 Key */
    0,  /* All other keys are undefined */
};

void keyboard_handler(struct regs *r)
{
    uchar scancode;

    /* Read from the keyboard's data buffer */
    scancode = inb(0x60);

    /* Check if the top bit is set (key release event) */
    if (scancode & 0x80)
    {
        scancode &= 0x7F; // Remove the "release" flag
        if (scancode == 0x2A || scancode == 0x36) // Shift keys
        {
            shift = false;
        }
    }
    else
    {
        /* Handle key press events */
        if (scancode == 0x2A || scancode == 0x36) // Shift keys
        {
            shift = true;
        }
        else if (scancode == 0x3A) // Caps Lock
        {
            caps_lock = !caps_lock; // Toggle Caps Lock state
        }
        else
        {

            /* Check if the key is printable */
            if (shift || caps_lock)
            {
                // If both Shift and Caps Lock are active, invert the case
                if (shift && caps_lock && kbdus_lower[scancode] >= 'a' && kbdus_lower[scancode] <= 'z')
                {
                    printf("%c", kbdus_lower[scancode]);
                    if(write_to_input_buffer){
                        input_buffer[kbd_inp_buf_index] = kbdus_lower[scancode];
                        if(kbdus_upper[scancode] == '\b'){
                            if(kbd_inp_buf_index <= 0){
                                kbd_inp_buf_index=0;
                            }else{
                                kbd_inp_buf_index--;
                            }
                        }else{
                            kbd_inp_buf_index++;
                        }
                    }
                    last_key = kbdus_lower[scancode];
                }
                else
                {
                    printf("%c", kbdus_upper[scancode]);
                    if(write_to_input_buffer){
                        input_buffer[kbd_inp_buf_index] = kbdus_upper[scancode];
                        if(kbdus_upper[scancode] == '\b'){
                            if(kbd_inp_buf_index <= 0){
                                kbd_inp_buf_index=0;
                            }else{
                                kbd_inp_buf_index--;
                            }
                        }else{
                            kbd_inp_buf_index++;
                        }
                    }
                    last_key = kbdus_upper[scancode];
                }
            }
            else
            {
                printf("%c", kbdus_lower[scancode]);
                if(write_to_input_buffer){
                    input_buffer[kbd_inp_buf_index] = kbdus_lower[scancode];
                    if(kbdus_upper[scancode] == '\b'){
                            if(kbd_inp_buf_index <= 0){
                                kbd_inp_buf_index=0;
                            }else{
                                kbd_inp_buf_index--;
                            }
                        }else{
                            kbd_inp_buf_index++;
                        }
                }
                last_key = kbdus_lower[scancode];
            }
        }
    }
}

void clear_input_buffer(){
    for(int x=0; x<128; x++){
        input_buffer[x] = '\0';
    }
}

/* Installs the keyboard handler into IRQ1 */
void keyboard_install()
{
    write_to_input_buffer = false;
    last_key = '\0';
    kbd_inp_buf_index = 0;
    for(int x=0; x<128; x++){
        input_buffer[x] = '\0';
    }
    irq_install_handler(1, keyboard_handler);
}

int input_num(char* prompt){
    clear_input_buffer();
    kbd_inp_buf_index = 0;
    printf("%s", prompt);
    write_to_input_buffer = true;
    last_key = '\0';
    while(last_key != '\n'){int a = inb(0x60);} //For some reason this makes everything work. I have no idea why!
    int result = input_buffer[0] - '0';
    write_to_input_buffer = false;
    last_key = '\0';
    return result;
}