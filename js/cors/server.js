var express = require('express');

// 10010端口的服务, 将当前目录作为http服务
var app = express();
app.use(express.static(__dirname))
app.listen(10010)

// 10011端口的服务, 返回数据

// 1. 修改响应头

var app2 = express();
app2.get("/", function(req, res){
    res.header("Access-Control-Allow-Origin", "*")
    res.send("你好")
})
app2.listen(10011)


// 2. jsonp


