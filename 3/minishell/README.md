# minishell
my own mini UNIX command interpreter.

# 프로젝트 설명
- Bash을 모방한 기초적인 동작이 가능한 쉘 프로그램 구현 (2인 팀 프로젝트)
- C, Makefile을 통한 프로그램 실행
- 입력 파싱 파트와 프로그램 실행 파트로 구분하여 팀 프로젝트 진행
- processes, file descriptors

Bash manual : https://www.gnu.org/software/bash/manual/bash.html

# 구현 사항
- redirection 동작 ('<' , '>' , '<<' , '>>')
- pipe ('|')
- bash와 동일 동작의 signal(ctrl-c, ctrl-d, ctrl-\ ) 처리
- echo, cd, pwd, export, unset, env, exit builtin 기능 구현(no option)

# 동작

```c
make
./minishell
```

![Alt text](./images/minishell.gif)

