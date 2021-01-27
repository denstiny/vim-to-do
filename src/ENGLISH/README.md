[中文文档](https://github.com/denstiny/vim-to-do/blob/main/README.md) | [English](https://github.com/denstiny/vim-to-do/tree/main/src/ENGLISH)  

## todo-list for neovim
![github.svg](../material/badge.svg)  

I’m the c++ novice,I like vim very much. Accidentally see this plug-in ` COC todolist`,it can help me manage my time,it’s very friendly,it can sync to your Github.But I can’t open vim forever,it’s impossible to keep an eye on vim to remind me.So I gave him some supplements,the code is rough,make do with it.
<BR>
<br>
<BR>
<i> This is an extension tool of coc-todolist,it is implemented entirely in C language,you can use it very simply,but only if you have one coc-todolist</i>
[coc-todolist](https://github.com/voldikss/coc-todolist)
![vim.gif](https://i.loli.net/2021/01/22/5ItjEyLrk6AUQ3J.gif)
##  Fix 
```shell
git clone https://github.com/denstiny/vim-to-do.git 
cd vim-to-do
make
```
## Deploy
Its configuration file is `include/config.h`    
#### prompt tone
If you need to wake uo with a prompt tone,you need to modify the`VOIDOCONFIG`parameter in config,the default is `false`  closed.
##### Modify prompt sound effect
```c
  #define VOIDOFILE "/mnt/home/todo-list/src/material/keli.mp3"
  // Default sound effect
```
Just change the audio file path. <u>Preferably less than three seconds of audio,do not play restrictions.</u>  
Playback uses [mpg123](https://github.com/dreamerc/mpg123) open source porjects.
#### Voice broadcast(English may be a bit awkward)
If you need vocie broadcast,change`EKHOCOFIG`parameter,the default is`false` closed.
<u>The use of [ekho](https://github.com/hgneng/ekho.git) residual sound</u>  
Use Linux package manager to install.
```shell
# arch
sudo pacman -S ekho
# ubuntu
sudo apt install ekho
# centos 
sudo yum install ekho
```
#####  Update log
* Update for the first time
	* Solve the problem of starting Caton  
	* Solve the problem that multiple entrusted tasks cannot be detected
	* Solve things without prompting
> demo  
![c__.gif](https://i.loli.net/2021/01/27/rqzKhXfGyYZBF3g.gif)
#### Contribution
##### <a href="https://github.com/zyl-hub"> zyl-hub <span>  <img border="0" src="https://avatars.githubusercontent.com/u/54789212?s=400&v=4" height="100" width="100" />
</a>


