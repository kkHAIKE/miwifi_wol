# 小米路由器 WOL 插件

介于之前 misstar 提供的原生插件停止维护了无法使用，思索着自己弄一个唤醒家里的 NAS 

搞了一天多才搞好一个这么简单的插件，终于知道小米路由器生态为啥这么差了，从软到硬都很渣，不是看到刷其他固件不稳定早放弃了

## 使用

### 部署页面
1. 修改 index.html 中的 appId 和 info(mac:ip，你要唤醒的机器要设定好静态 DHCP)
2. 找个外网 ip 部署这个 index.html，比如：http://1.2.3.4/index.html，记住这个地址
3. 可以直接用的 wol.go 构建服务器，也可以部署一个 nginx

### 构建
1. 去 http://www1.miwifi.com/miwifi_open.html 左下方下载 插件开发文档，里面包含 开发文档 和 linux 交叉编译 sdk，找个 64 的 linux 系统解压
2. 将本目录放在解压后的 sdk_package 目录中，可为 sdk_package/wol
3. 进入 wol 目录，用 make wol 构建二进制程序 build/wol
4. 将 wol程序 和 start_script启动脚本 打一个压缩包 pac.zip

### 平台创建
1. 参照 之前解压的 开发文档 或者这个地址 https://dev.mi.com/docs/routerplugin/user_guide/
2. 参照教程本地生成 私钥 client.key，证书请求 client.csr(注意用户id)
3. 一定要将证书请求提交到 dev.mi.com 管理控制台->路由器插件->申请开发者证书得到 client.pem
4. 教程中 开通小米账号接入服务 填入 部署页面 中的那个地址

### 打包
1. 一定使用 https://d.miwifi.com/plugin/mipk 这个打包工具，千万不要使用 linux 的那个 plugin_packager_x64，这个打包出来的会让路由器的 plugincenter 崩溃，我在这上面卡了半天多时间，windows 的没测试，在线的一定 OK
2. 可以用我 xiaomi.project 中已经上传的图片链接
3. 把打包的 mpk 部署在外网链接，生成一个二维码，用手机 app 扫码安装就行
