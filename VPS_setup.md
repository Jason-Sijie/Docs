#在阿里云的ecs（centos）上搭建ssserver

1. 用pip2.7安装shadowsocks
`pip2.7 install shadowsocks`
注意不要使用python36的环境安装

2. 配置文件
`vim /etc/shadowsocks.json`
配置文件的内容如下
```
{
	"server":"0.0.0.0",
	"server_port":8388,
	"local_address": "127.0.0.1",
	"local_port": 1080,
	"password":
	"timeout":300,
	"method": "aes-256-cfb:,
	"fast_open": false,
	"workers": 1
}
```
注意"server"一定要填写"0.0.0.0"，不能填写本机的外网ip
"server_port"需要在防火墙下授权，如果防火墙开启的话

3. 阿里云安全组设置
在阿里云的安全组中开放 tcp入/出方向的对应端口（此处为8388）

4. 在服务器上后台运行ss
`/usr/bin/ssserver -c /etc/shadowsocks.json -d start`

5. linux客户端连接
* 首先用apt安装shadowsocks
* 配置文件
	`vim /etc/sslocal.json`

	```{
		"server":"服务器的外网ip",
		"server_port":8388,
		"local_address": "127.0.0.1",
		"local_port": 1080,
		"password":
		"timeout":300,
		"method": "aes-256-cfb:,
		"fast_open": false,
		"workers": 1
	}
	```
* 最后在setting的network中将proxy设置成手动，并且在socks一栏中输入127.0.0.1, port 8388（此处的设置为全局设置）
