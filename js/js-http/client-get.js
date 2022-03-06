var http = require('http');
var querystring = require('querystring');
var data = {
  page: 1,
  size: 20
};//这是需要提交的数据
var content = querystring.stringify(data);
console.log("querystring: ",content);

var options = {
  hostname: 'http://172.19.4.145',
  port: 8080,
  path: '/sobeyhive-cdplb/v1/cdplb/task/?' + content,
  method: 'GET'
};
console.log('path: ', options.path);

var req = http.request(options, function (res) {
  console.log('STATUS: ' + res.statusCode);
  console.log('HEADERS: ' + JSON.stringify(res.headers));
  res.setEncoding('utf8');
  res.on('data', function (chunk) {
    console.log('BODY: ' + chunk);
  });
});
req.on('error', function (e) {
  console.log('problem with request: ' + e.message);
});
req.end();