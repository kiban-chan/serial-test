#include <termios.h>
#include <unistd.h>
#include <stdio.h>

#define SERIAL_PORT "/dev/ttyS0"
#define BAUD_RATE B115200

static struct termios termios_new;

void set_serial_config()
{
  termios_new.c_iflag = 0; /* 特に設定するもの無かった */
  termios_new.c_oflag = 0; /* 特に設定するもの無かった */
  termios_new.c_cflag = CS8 | CREAD; /* 文字サイズ8bit, 受信有効 */
  termios_new.c_lflag = 0;

  if(tcgetattr(0, &termios_new) != 0){
    perror("tcgetattr() error");
  }else if(cfsetispeed(&termios_new, BAUD_RATE) != 0){
    perror("cfsetispeed() error");
  }else if(tcsetattr(0, TCSANOW, &termios_new) != 0){
    perror("tcsetattr() error");
  }

}
