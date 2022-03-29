
function add(){
    let sum = 0;
    for(let i = 0, j = arguments.length; i<j; ++i){
        sum += arguments[i];
    }
    return sum;
}

let sumTotal = add(1,2,3,4,5,6,7,8,9,10);
console.log(sumTotal);

function makeAdder(a){
    return function(b){
        return a + b;
    };
}

let x = makeAdder(5);
let y = x(7);
console.log(y);

//!

function hiveData2TaskDetailData(index, hiveData, taskData) {

    taskData.index = index;
    taskData.taskId = hiveData.taskId;
    taskData.name = hiveData.name;  //任务名称
    taskData.duration = hiveData.duration;   //素材总时长
    taskData.taskState = hiveData.taskState;   //状态
    taskData.percent = hiveData.percent;  //任务完成百分比
    taskData.transcodingTime = hiveData.transcodingTime;  //用时
    taskData.transcodingSpeed = hiveData.transcodingSpeed;   //实时效率
    taskData.receiveDate = hiveData.receiveDate;  //接收时间
    taskData.startDate =hiveData.startDate;   //开始时间

    return taskData;
}   

function hiveDataList2TaskDetailDataList(hiveDataList, taskDataList){

    for(let i=0; i<hiveDataList.length; i++){
        let taskData = {};
        console.log(typeof(i));
        taskData = hiveData2TaskDetailData(i, hiveDataList[i], taskData);
        taskDataList.push(taskData);
    }

    return taskDataList;
}

let taskData = {};
let hiveData = {};
let taskDataList = [];
let hiveDataList = [];

//taskData.index = index;
hiveData.taskId = 0;
hiveData.name = 1;  //任务名称
hiveData.duration = 2;   //素材总时长
hiveData.taskState = 3;   //状态
hiveData.percent = 4;  //任务完成百分比
hiveData.transcodingTime = 5;  //用时
hiveData.transcodingSpeed = 6;   //实时效率
hiveData.receiveDate = 7;  //接收时间
hiveData.startDate = 8;   //开始时间

hiveData2TaskDetailData(0, hiveData, taskData);
console.log('after hiveData2TaskDetailData');
console.log('taskData: ', taskData);
console.log('hiveData: ', hiveData);

hiveDataList.push(hiveData);
hiveDataList.push(hiveData);
hiveDataList.push(hiveData);

taskDataList = hiveDataList2TaskDetailDataList(hiveDataList, taskDataList);
console.log('after hiveDataList2TaskDetailDataList');
console.log('taskDataList: ', taskDataList);