#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MSG_Q_NAME  "/MSG_Q"
#define NO_MAX_MSG  10
#define MAX_MSG     1024
#define STOP_CMD    "exit"

int main(int agrc, char *argv[]) {
  mqd_t msg_q;
  struct mq_attr attr;
  int mq_len;
  int stop_len;
  char message[MAX_MSG] = "hello world";
  char stop[MAX_MSG] = "exit";

  attr.mq_flags = 0;
  attr.mq_maxmsg = NO_MAX_MSG;
  attr.mq_msgsize = MAX_MSG;
  attr.mq_curmsgs = 0;

  msg_q = mq_open (MSG_Q_NAME,O_WRONLY,S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH, &attr);
  if ( -1 == msg_q) {
    perror("mq_open");
    _exit(-1);
  }

/// try 1

  // for(int i=0;i<5;i++){
  //   printf("Send> %s\n",message);
  //   sleep(1);
  //   mq_len = strlen(message);
    
  //   if ( -1 == mq_send(msg_q, message, mq_len, 0)) {
  //     perror("mq_send");
  //     mq_close(msg_q);
  //     mq_unlink(MSG_Q_NAME);
  //     exit(-1);
  //     }

  // }


  // strcpy(message,stop);


  //     printf("Send> %s\n",message);
      
  //     mq_close(msg_q);
  //     mq_unlink(MSG_Q_NAME);


/*
*   try 2 : completed
*/

for(int i=0;i<=4;i++){
  mq_len = strlen(message);
  printf("Send> %s\n",message);
  sleep(1);

    if ( -1 == mq_send(msg_q, message, mq_len, 0)) {
      perror("mq_send");
      mq_close(msg_q);
      mq_unlink(MSG_Q_NAME);
      exit(-1);
      }
    
    if(i == 4){
      stop_len = strlen(stop);
      sleep(1);
      printf("Send> %s\n",stop);

      if ( -1 == mq_send(msg_q, stop, stop_len, 0)) {
      perror("mq_send");
      mq_close(msg_q);
      mq_unlink(MSG_Q_NAME);
      exit(-1);
      }
    
    }
  }

      mq_close(msg_q);
      mq_unlink(MSG_Q_NAME);

/// try 3 : strcpy 

// for(int i=0;i<=4;i++){
//   mq_len = strlen(message);
//   printf("Send> %s\n",message);
//   sleep(1);

//   if(i == 4){
    
//       strcpy(message,stop);
//       stop_len = strlen(message);
//       printf("Send> %s\n",message);

//     }

//     if ( -1 == mq_send(msg_q, message, mq_len, 0)) {
//       perror("mq_send");
//       mq_close(msg_q);
//       mq_unlink(MSG_Q_NAME);
//       exit(-1);
//       }
  
//   }

//       mq_close(msg_q);
//       mq_unlink(MSG_Q_NAME);




///
  // printf("Enter \"exit\"  to stop: \n");
  // do {
  //   bzero(message, MAX_MSG);
  //   printf("Send> ");
  //   fgets(message,sizeof(message), stdin);
    // message[strlen(message)-1]='\0';
    // mq_len = strlen(message);
    
  //   if ( -1 == mq_send(msg_q, message, mq_len, 0)) {
  //     perror("mq_send");
  //     mq_close(msg_q);
  //     mq_unlink(MSG_Q_NAME);s
  //     _exit(-1);
  //   }
  // } while (!(0 == strcmp(message, STOP_CMD)));

  // printf("mq_writer: Exit\n");
  // mq_close(msg_q);
  // mq_unlink(MSG_Q_NAME);
  return 0;
}
