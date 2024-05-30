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
- [Docker](#docker)
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

####


## Cron jobs
## Event-driven automation
## Docker
## Kernel modules
