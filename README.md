# MINI_SHELL
MiniShell will introduce you to the world of shells, which provide a convenient text interface to interact with your system. Shells might seem very easy to understand but have very specific and defined behavour in almost every single case, most of which will need to be handled properly.
## Shell in a nutshell
When you start a terminal (such as the GNOME Terminal or Konsole on Linux or iTerm2 on macOS) running the Bash shell, you're greeted with a prompt. A prompt is a symbol, usually a dollar sign ($), indicating that the shell is waiting for your input. Of course, knowing what you're supposed to type is another matter entirely.
This probably comes across as unfriendly, but it's actually a perfectly succinct representation of the many connotations around the term "Bash." To many new users, there's no separation between the concept of Bash and the concept of Linux or Unix: it's the proverbial black-screen-with-green-text into which you're supposed to code what your computer does next. That conflates the Bash shell with the commands you type into the shell. It's important to understand that they're two separate things: Bash is just an application, and its primary job is to run other applications (in the form of commands) that are installed on the same system.
## Requirements
This project is requires 'readline'. you can install it using the following command:
```Bash
brew install readline
```
## Running
After installing readline you can compile & run *minishell* with the following command
```Bash
git clone git@github.com:Ajjig/MINI_SHELL.git && cd MINI_SHELL && Make && ./minishell
```
