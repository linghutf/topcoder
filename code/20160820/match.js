
function isMatch(m,str){
  var g = new RegExp('^'+m+'$');//不需要/ /符号
  //var g = '/'+m+'/g';//不是regexp对象
  console.log(g);
  var res = str.match(g);
  console.log(res);
  return res!=null;//是否匹配
}

(function(){
  var m = process.argv[2];
  var s = process.argv[3];
  console.log(isMatch(m,s));
})();
