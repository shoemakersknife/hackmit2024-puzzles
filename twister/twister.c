#include "out.h"



int _init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  iVar1 = __gmon_start__();
  return iVar1;
}



void FUN_00101020(void)

{
  (*(code *)(undefined *)0x0)();
  return;
}



void FUN_00101130(void)

{
  __cxa_finalize();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int puts(char *__s)

{
  int iVar1;
  
  iVar1 = puts(__s);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int setresgid(__gid_t __rgid,__gid_t __egid,__gid_t __sgid)

{
  int iVar1;
  
  iVar1 = setresgid(__rgid,__egid,__sgid);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int printf(char *__format,...)

{
  int iVar1;
  
  iVar1 = printf(__format);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
  int iVar1;
  
  iVar1 = snprintf(__s,__maxlen,__format);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int close(int __fd)

{
  int iVar1;
  
  iVar1 = close(__fd);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

ssize_t read(int __fd,void *__buf,size_t __nbytes)

{
  ssize_t sVar1;
  
  sVar1 = read(__fd,__buf,__nbytes);
  return sVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void srand(uint __seed)

{
  srand(__seed);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

char * fgets(char *__s,int __n,FILE *__stream)

{
  char *pcVar1;
  
  pcVar1 = fgets(__s,__n,__stream);
  return pcVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int strcmp(char *__s1,char *__s2)

{
  int iVar1;
  
  iVar1 = strcmp(__s1,__s2);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

time_t time(time_t *__timer)

{
  time_t tVar1;
  
  tVar1 = time(__timer);
  return tVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

char * gets(char *__s)

{
  char *pcVar1;
  
  pcVar1 = gets(__s);
  return pcVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

__gid_t getegid(void)

{
  __gid_t _Var1;
  
  _Var1 = getegid();
  return _Var1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int setvbuf(FILE *__stream,char *__buf,int __modes,size_t __n)

{
  int iVar1;
  
  iVar1 = setvbuf(__stream,__buf,__modes,__n);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int open(char *__file,int __oflag,...)

{
  int iVar1;
  
  iVar1 = open(__file,__oflag);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void exit(int __status)

{
                    // WARNING: Subroutine does not return
  exit(__status);
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int rand(void)

{
  int iVar1;
  
  iVar1 = rand();
  return iVar1;
}



void processEntry _start(undefined8 param_1,undefined8 param_2)

{
  undefined auStack_8 [8];
  
  __libc_start_main(main,param_2,&stack0x00000008,0,0,param_1,auStack_8);
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Removing unreachable block (ram,0x00101283)
// WARNING: Removing unreachable block (ram,0x0010128f)

void deregister_tm_clones(void)

{
  return;
}



// WARNING: Removing unreachable block (ram,0x001012c4)
// WARNING: Removing unreachable block (ram,0x001012d0)

void register_tm_clones(void)

{
  return;
}



void __do_global_dtors_aux(void)

{
  if (completed_0 != '\0') {
    return;
  }
  FUN_00101130(__dso_handle);
  deregister_tm_clones();
  completed_0 = 1;
  return;
}



void frame_dummy(void)

{
  register_tm_clones();
  return;
}



void seed(undefined8 param_1)

{
  time_t tVar1;
  ssize_t sVar2;
  undefined4 local_10;
  int local_c;
  
  tVar1 = time((time_t *)0x0);
  srand((uint)tVar1);
  local_c = open("/dev/urandom",0);
  if (local_c == -1) {
    puts("error opening /dev/urandom");
                    // WARNING: Subroutine does not return
    exit(1);
  }
  sVar2 = read(local_c,&local_10,4);
  if (sVar2 != 4) {
    puts("error reading /dev/urandom");
                    // WARNING: Subroutine does not return
    exit(1);
  }
  close(local_c);
  seed_rand(param_1,local_10);
  return;
}



void canary(void)

{
  char *pcVar1;
  char local_118 [268];
  uint local_c;
  
  puts("");
  puts("      canary select");
  puts("");
  local_c = gen_rand(rng);
  printf("[\x1b[32m*\x1b[0m] canary_id: %u\n",(ulong)local_c);
  printf("[\x1b[34m*\x1b[0m] regenerate? (y/n) ");
  pcVar1 = fgets(local_118,0xff,stdin);
  if (pcVar1 != (char *)0x0) {
    printf("[\x1b[34m*\x1b[0m]\x1b[34m user input: ");
    printf(local_118);
    puts("\x1b[0m");
    while( true ) {
      while (local_118[0] == 'y') {
        local_c = gen_rand(rng);
        printf("[\x1b[32m*\x1b[0m] canary_id: %u\n",(ulong)local_c);
        printf("[\x1b[34m*\x1b[0m] regenerate? (y/n) ");
        pcVar1 = fgets(local_118,0xff,stdin);
        if (pcVar1 == (char *)0x0) {
          return;
        }
        printf("[\x1b[34m*\x1b[0m]\x1b[34m user input: ");
        printf(local_118);
        puts("\x1b[0m");
      }
      if (local_118[0] == 'n') break;
      printf("[\x1b[31m*\x1b[0m] invalid action, please try again: ");
      pcVar1 = fgets(local_118,0xff,stdin);
      if (pcVar1 == (char *)0x0) {
        return;
      }
      printf("[\x1b[34m*\x1b[0m]\x1b[34m user input: ");
      printf(local_118);
      puts("\x1b[0m");
    }
  }
  return;
}



void game(void)

{
  int iVar1;
  char *pcVar2;
  uint auStack_278 [12];
  uint auStack_248 [12];
  char local_218 [256];
  char local_118 [260];
  int local_14;
  int local_10;
  int local_c;
  
  local_14 = gen_rand_no_state_update(rng);
  do {
    puts("");
    puts("      arithmetic game");
    puts("");
    for (local_c = 0; local_c < 10; local_c = local_c + 1) {
      iVar1 = rand();
      auStack_278[local_c] = iVar1 % 100 + 5;
      iVar1 = rand();
      auStack_248[local_c] = iVar1 % 100 + 5;
    }
    for (local_10 = 0; local_10 < 10; local_10 = local_10 + 1) {
      snprintf(local_218,0xff,"%d",(ulong)(auStack_278[local_10] + auStack_248[local_10]));
      printf("[\x1b[34m*\x1b[0m] %d. %d + %d: ",(ulong)(local_10 + 1),(ulong)auStack_278[local_10],
             (ulong)auStack_248[local_10]);
      gets(local_118);
      iVar1 = strcmp(local_118,local_218);
      if (iVar1 == 0) {
        puts("[\x1b[32m*\x1b[0m]\x1b[32m Correct!\x1b[0m");
      }
      else {
        puts("[\x1b[31m*\x1b[0m]\x1b[31m Wrong!\x1b[0m");
        local_10 = local_10 + -1;
      }
    }
    puts("");
    puts("      you finished!");
    puts("");
    printf("[\x1b[34m*\x1b[0m] play again? (y/n) ");
    pcVar2 = fgets(local_218,0xff,stdin);
    while( true ) {
      if (pcVar2 == (char *)0x0) {
        return;
      }
      if ((local_218[0] == 'y') || (local_218[0] == 'n')) break;
      printf("[\x1b[31m*\x1b[0m] invalid action, please try again: ");
      pcVar2 = fgets(local_218,0xff,stdin);
    }
  } while (local_218[0] != 'n');
  iVar1 = gen_rand(rng);
  if (iVar1 == local_14) {
    return;
  }
  puts("***** stack smashing detected *****");
                    // WARNING: Subroutine does not return
  exit(1);
}



void welcome(void)

{
  puts("");
  puts("       .-\"-.");
  puts("      /  ,~a\\_");
  puts("      \\  \\__))>     welcome to TWISTER");
  puts("      ,) .\" \\        arithmetic game");
  puts("     /  (    \\");
  puts("    /   )    ;     [c] canary select");
  puts("   /   /     /     [p] play game");
  puts(" ,/_.\'`  _.-`      [e] exit");
  puts("  /_/`\"\\\\___");
  puts("       `~~~`");
  puts("");
  printf("[\x1b[34m*\x1b[0m]: ");
  return;
}



void start(void)

{
  char *pcVar1;
  char local_108 [256];
  
  welcome();
  pcVar1 = fgets(local_108,0xff,stdin);
  do {
    if (pcVar1 == (char *)0x0) {
      return;
    }
    if (local_108[0] == 'c') {
      canary();
      welcome();
    }
    else if (local_108[0] == 'p') {
      game();
      welcome();
    }
    else {
      if (local_108[0] == 'e') {
        return;
      }
      printf("[\x1b[31m*\x1b[0m] invalid action, please try again: ");
    }
    pcVar1 = fgets(local_108,0xff,stdin);
  } while( true );
}



undefined8 main(void)

{
  __gid_t __rgid;
  
  setvbuf(stdout,(char *)0x0,2,0);
  __rgid = getegid();
  setresgid(__rgid,__rgid,__rgid);
  seed(rng);
  start();
  return 0;
}



void seed_rand(int *param_1,int param_2)

{
  int local_c;
  
  if (param_2 == 0) {
    puts("seed cannot be 0");
                    // WARNING: Subroutine does not return
    exit(1);
  }
  *param_1 = param_2;
  for (local_c = 1; local_c < 0x270; local_c = local_c + 1) {
    param_1[local_c] =
         ((uint)param_1[local_c + -1] >> 0x1e ^ param_1[local_c + -1]) * 0x6c078965 + local_c;
  }
  param_1[0x270] = 0x270;
  return;
}



uint temper(uint param_1)

{
  param_1 = param_1 ^ param_1 >> 0xb;
  param_1 = param_1 ^ (param_1 & 0x13a58ad) << 7;
  param_1 = param_1 ^ (param_1 & 0x1df8c) << 0xf;
  return param_1 ^ param_1 >> 0x12;
}



void twist(long param_1)

{
  uint uVar1;
  int local_c;
  
  for (local_c = 0; local_c < 0x270; local_c = local_c + 1) {
    uVar1 = *(uint *)(param_1 + (long)((local_c + 1) % 0x270) * 4);
    *(uint *)(param_1 + (long)local_c * 4) =
         *(uint *)(param_1 + (long)((local_c + 0x18d) % 0x270) * 4) ^
         (uVar1 & 0x7fffffff | *(uint *)(param_1 + (long)local_c * 4) & 0x80000000) >> 1;
    if ((uVar1 & 1) != 0) {
      *(uint *)(param_1 + (long)local_c * 4) = *(uint *)(param_1 + (long)local_c * 4) ^ 0x9908b0df;
    }
  }
  *(undefined4 *)(param_1 + 0x9c0) = 0;
  return;
}



void gen_rand(long param_1)

{
  int iVar1;
  
  if (0x26f < *(int *)(param_1 + 0x9c0)) {
    twist(param_1);
    *(undefined4 *)(param_1 + 0x9c0) = 0;
  }
  iVar1 = *(int *)(param_1 + 0x9c0);
  *(int *)(param_1 + 0x9c0) = iVar1 + 1;
  temper(*(undefined4 *)(param_1 + (long)iVar1 * 4));
  return;
}



void gen_rand_no_state_update(long param_1)

{
  if (0x26f < *(int *)(param_1 + 0x9c0)) {
    twist(param_1);
    *(undefined4 *)(param_1 + 0x9c0) = 0;
  }
  temper(*(undefined4 *)(param_1 + (long)*(int *)(param_1 + 0x9c0) * 4));
  return;
}



uint un_xor_right(uint param_1,int param_2)

{
  int local_10;
  uint local_c;
  
  local_c = param_1;
  for (local_10 = 1; local_10 <= (int)(0x20 / (long)param_2); local_10 = local_10 + 1) {
    local_c = local_c ^ param_1 >> ((char)local_10 * (char)param_2 & 0x1fU);
  }
  return local_c;
}



uint un_xor_left_mask(uint param_1,uint param_2,int param_3)

{
  byte bVar1;
  uint local_1c;
  int local_10;
  uint local_c;
  
  bVar1 = (byte)param_3;
  local_c = (1 << (bVar1 & 0x1f)) - 1;
  local_1c = param_1;
  for (local_10 = 0; local_10 < (int)(0x20 / (long)param_3); local_10 = local_10 + 1) {
    local_1c = local_1c ^ (local_1c & local_c) << (bVar1 & 0x1f) & param_2;
    local_c = local_c << (bVar1 & 0x1f);
  }
  return local_1c;
}



undefined4 un_temper(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = un_xor_right(param_1,0x12);
  uVar1 = un_xor_left_mask(uVar1,0xefc60000,0xf);
  uVar1 = un_xor_left_mask(uVar1,0x9d2c5680,7);
  uVar1 = un_xor_right(uVar1,0xb);
  return uVar1;
}



void predict(long param_1,long param_2)

{
  undefined4 uVar1;
  int local_c;
  
  for (local_c = 0; local_c < 0x270; local_c = local_c + 1) {
    uVar1 = un_temper(*(undefined4 *)(param_2 + (long)local_c * 4));
    *(undefined4 *)(param_1 + (long)local_c * 4) = uVar1;
  }
  *(undefined4 *)(param_1 + 0x9c0) = 0x270;
  gen_rand(param_1);
  return;
}



void _fini(void)

{
  return;
}



