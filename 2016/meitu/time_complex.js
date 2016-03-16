
function f1(n){
  console.time();
  for(var i=0;i<n;i*=2){
    for(var j=i/2;j<i;++j){}
  }
  return console.timeEnd();
}

function f2(n){
  return (Math.log(n)/Math.log(2)*Math.pow(2,n));
}

(function(){
  var n = parseInt(process.argv[2]);
  console.log('n:'+n);
  console.log('f1:'+f1(n));
  console.log('f2:'+f2(n));
})();
