## todo-list
![github.svg](./src/material/badge.svg)  
  
> 我是一名c++新手，我对vim非常喜欢，偶然看到这个插件`coc-todolist`
> 他可以帮助我管理时间，他是非常友好的，可以同步到你的github，但
> 是我不可能永远打开vim，也不可能一直盯着vim是否给我提醒，所以
> 所以我给他做了一些补充，代码很粗糙，凑合者用吧

<BR>
<br>
<BR>

<i> 这是一个coc-todolist的扩展工具，他是完全使用c语言实现的
你可以非常简单的使用他，但是前提你得拥有coc-todolist</i>
[coc-todolist](https://github.com/voldikss/coc-todolist)

![vim.gif](https://i.loli.net/2021/01/22/5ItjEyLrk6AUQ3J.gif)

## 安装
```shell
git clone https://github.com/denstiny/vim-to-do.git 
cd vim-to-do
make
```
## 配置
他的配置文件是 `include/config.h`    
#### 提示音
如果你需要提醒的时候带有提示音的效果，你需要修改config中的`VOIDOCONFIG` 参数，默认为`false`  关闭   
##### 修改提示音效
```c
  #define VOIDOFILE "/mnt/home/todo-list/src/material/keli.mp3"
  // 默认音效
```
更改音频文件路径即可. <u>最好是小于三秒的音频，未做播放限制</u>  
播放使用的是 [mpg123](https://github.com/dreamerc/mpg123) 开源项目  

#### 语音播报(英语可能有点别扭)
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
#### 贡献

##### <a href="https://github.com/zyl-hub"> zyl-hub <span>  <img border="0" src="https://avatars.githubusercontent.com/u/54789212?s=400&v=4" height="100" width="100" />
</a>
