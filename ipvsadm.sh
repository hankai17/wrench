ipvsadm -C
ipvsadm -At  192.168.116.128:80 -s rr    #添加一个本机不存在的端口服务
ipvsadm -ln
ipvsadm -at 192.168.116.128:80 -r 192.168.2.2:80 -m  #添加后端服务
ipvsadm -ln
curl -v  "http://192.168.116.128/"
