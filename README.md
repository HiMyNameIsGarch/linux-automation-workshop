# LEAD Workshop at GDSC
LEAD stands for Linux Empowered Automation for Developers and it's intended to
help you have a better understanding of your system, automate tasks and
make your life much more easier while working with Linux at home or at work.

Here I will put some notes from the presentation and some additional
resources that you can use to learn more about the topics we discussed.

## Table of Contents
- [Shell Scripting](#shell-scripting)
- [Cron jobs](#cron-jobs)
- [Event-driven automation](#event-driven-automation)
- [Tmux](#tmux)
- [Kernel modules](#kernel-modules)

## Compile the latex file
```
pdflatex -output-directory=build/ main.tex
```
Then you can open it in Firefox or any other PDF viewer.

## Shell Scripting
#### Where to put your scripts?
- `/usr/local/bin or /usr/local/sbin`
- `/usr/bin or /usr/sbin`
- `~/bin`
- `~/.local/bin`
##### Don't forget to add the path to your scripts ( $PATH ) in your profile file.
#### What shebang to use?
- `#!/bin/bash` when your are 100% sure this will be a bash script
- `#!/bin/sh` when you want to be POSIX compliant ( required for scripts that will run on multiple systems or dispatchers )
- `#!/usr/bin/env bash` when you want to use the system's bash

#### Shell
- [Bash Guide](https://guide.bash.academy/)
- [Advanced Bash Scripting Guide](https://tldp.org/LDP/abs/html/index.html)
- [ShellCheck](https://www.shellcheck.net/)
- [Bash Pitfalls](https://mywiki.wooledge.org/BashPitfalls)
- [Dash] (https://wiki.archlinux.org/title/Dash)

####  Cron jobs
- [Crontab Guru](https://crontab.guru/)
- [Crontab Generator](https://crontab-generator.org/)
- [Cron Howto](https://help.ubuntu.com/community/CronHowto)

#### Event-driven automation
- [Inotify] (https://www.man7.org/linux/man-pages/man7/inotify.7.html)
- [cgroups] (https://www.kernel.org/doc/html/latest/admin-guide/cgroup-v1/cgroups.html)
- [acpid] (https://www.kernel.org/doc/html/latest/admin-guide/acpi/events.html)
- [udev rules] (https://www.kernel.org/doc/html/latest/admin-guide/udev.html)

#### Tmux
- [Tmux cheatsheet](https://tmuxcheatsheet.com/)
- [Tmux manual](https://github.com/tmux/tmux/wiki/Getting-Started)

#### Kernel modules
- [Linux Kernel Module Programming Guide](https://tldp.org/LDP/lkmpg/2.6/html/index.html)
- [Kernel newbies] (https://kernelnewbies.org/)
