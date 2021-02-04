
<!-- vim-markdown-toc GFM -->

* [todo-list](#todo-list)
* [安装](#安装)
* [配置](#配置)
	* [提示音](#提示音)
			* [修改提示音效](#修改提示音效)
			* [语音播报(英语可能有点别扭)](#语音播报英语可能有点别扭)
* [更新日志](#更新日志)
* [贡献](#贡献)

<!-- vim-markdown-toc -->
<font size=3>[中文文档](https://github.com/denstiny/vim-to-do/blob/main/README.md) | [English](https://github.com/denstiny/vim-to-do/tree/main/src/ENGLISH)</font>  
## todo-list
![github.svg](./src/material/badge.svg)  
  
> 我是一名c++新手，我对vim非常喜欢，偶然看到这个插件`coc-todolist`
> 他可以帮助我管理时间，他是非常友好的，可以同步到你的github，但
> 是我不可能永远打开vim，也不可能一直盯着vim是否给我提醒，所以
> 所以我给他做了一些补充，因为我是新手，代码是粗糙的

<BR>
<br>
<BR>

<i> 这是一个coc-todolist的扩展工具，他是完全使用c语言实现的
你可以非常简单的使用他，但是前提你得拥有coc-todolist</i>
[coc-todolist](https://github.com/voldikss/coc-todolist)


## 安装
```shell
git clone https://github.com/denstiny/vim-to-do.git 
cd vim-to-do
make
```
## 配置
他的配置文件是 `include/config.h`    
### 提示音
如果你需要提醒的时候带有提示音的效果，你需要修改config中的`VOIDOCONFIG` 参数，默认为`false`  关闭   
##### 修改提示音效
```c
  #define VOIDOFILE "/mnt/home/todo-list/src/material/keli.mp3"
  // 默认音效
```
更改音频文件路径即可. <u>最好是小于三秒的音频，未做播放限制</u>  
播放使用的是 [mpg123](https://github.com/dreamerc/mpg123) 开源项目  

##### 语音播报(英语可能有点别扭)
如果你需要语音播报 更改`EKHOCOFIG` 参数，默认为 `false` 关闭
<u>使用的是[ekho](https://github.com/hgneng/ekho.git) 余音</u>  
使用 linux 包管理器安装
```shell
# arch
sudo pacman -S ekho
# ubuntu
sudo apt install ekho
# centos 
sudo yum install ekho
```
##  更新日志

* 2021-02-04 
	* 添加结束时的提醒判断
* 2021-02-01
	* 解决启动卡顿  
	* 解决无法检测多个代办任务 
	* 解决事件不提示
> 演示
![c__.gif](https://i.loli.net/2021/01/27/rqzKhXfGyYZBF3g.gif)
## 贡献

<font size=3><a href="https://github.com/zyl-hub"> zyl-hub <span>  <img border="0" src="https://avatars.githubusercontent.com/u/54789212?s=400&v=4" height="100" width="100" /></font>
</a> <br> 
<font size=3>  感谢[coc-todolist](https://github.com/voldikss/coc-todolist)</font>
