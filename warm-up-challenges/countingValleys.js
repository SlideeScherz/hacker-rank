
function countingValleys(steps, path) {
  
  var valleys = 0;
  var y = 0;
  var inValley = false;

  for( let x = 0; x < steps; x++){
    
    path[x] === 'U' ? y++ : y--;
    
    if(inValley && y === 0){
      valleys++;
      inValley = false;
    }    
    
    else if(y < 0){
      inValley = true;
    }
  }
  

  
  return valleys;
  
}

let temp = "DDUDUDDUDDUDDUUUUDUDDDUUDDUUDDDUUDDUUUUUUDUDDDDUDDUUDUUDUDUUUDUUUUUDDUDDDDUDDUDDDDUUUUDUUDUUDUUDUDDD"
let s = [...temp];

console.log(s.length);


countingValleys(100, s);