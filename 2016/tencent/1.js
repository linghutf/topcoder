/*
 *
 * 闭包作用域
 * 引用的对象没有释放
 *
 */
var x = 1;
(function(){
  var x=2;
  var y=2;
})()

console.log(x==y);
