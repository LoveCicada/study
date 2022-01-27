# my-project

> A vue.js project

## Build Setup

``` bash
# install dependencies
npm install

# serve with hot reload at localhost:8080
npm run dev

# build for production with minification
npm run build

# build for production and view the bundle analyzer report
npm run build --report

# run unit tests
npm run unit

# run e2e tests
npm run e2e

# run all tests
npm test
```

For a detailed explanation on how things work, check out the [guide](http://vuejs-templates.github.io/webpack/) and [docs for vue-loader](http://vuejs.github.io/vue-loader).

## introduce
```
index.html: 整个项目的入口文件

main.js: 整个项目的逻辑主文件

Vue实例: vue的实例化对象

包含: el / tem / com

temp: 模板中可以写html / 调用其他组件

<App/>:
代表模板要执行的组件文件,跟App.vue中的name属性有关
comp:
组件组中要包含需要调用的组件名,例如上面模板调用了<App/>,那么组件组中就一定要包含App组件
import:
import用于导入需要依赖的文件,例如上方组件组中,
想要引入App组件,那么首先要使用import引入这个组件文件
import .. from ..: import 后面是自己起的名字,from后面是组件的名字
```

- `project struct`
```
├── index.html                      入口页面
    ├── build                           构建脚本目录
    │   ├── build-server.js                 运行本地构建服务器，可以访问构建后的页面
    │   ├── build.js                        生产环境构建脚本
    │   ├── dev-client.js                   开发服务器热重载脚本，主要用来实现开发阶段的页面自动刷新
    │   ├── dev-server.js                   运行本地开发服务器
    │   ├── utils.js                        构建相关工具方法
    │   ├── webpack.base.conf.js            wabpack基础配置
    │   ├── webpack.dev.conf.js             wabpack开发环境配置
    │   └── webpack.prod.conf.js            wabpack生产环境配置
    ├── config                          项目配置
    │   ├── dev.env.js                      开发环境变量
    │   ├── index.js                        项目配置文件
    │   ├── prod.env.js                     生产环境变量
    │   └── test.env.js                     测试环境变量
    ├── mock                            mock数据目录
    │   └── hello.js
    ├── package.json                    npm包配置文件，里面定义了项目的npm脚本，依赖包等信息
    ├── src                             项目源码目录    
    │   ├── main.js                         入口js文件
    │   ├── app.vue                         根组件
    │   ├── components                      公共组件目录
    │   │   └── title.vue
    │   ├── assets                          资源目录，这里的资源会被wabpack构建
    │   │   └── images
    │   │       └── logo.png
    │   ├── routes                          前端路由
    │   │   └── index.js
    │   ├── store                           应用级数据（state）
    │   │   └── index.js
    │   └── views                           页面目录
    │       ├── hello.vue
    │       └── notfound.vue
    ├── static                          纯静态资源，不会被wabpack构建。
    └── test                            测试文件目录（unit&e2e）
        └── unit                            单元测试
            ├── index.js                        入口脚本
            ├── karma.conf.js                   karma配置文件
            └── specs                           单测case目录
                └── Hello.spec.js

```