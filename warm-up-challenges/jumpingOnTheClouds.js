


/** C = cloud arr */
function jumpingOnClouds(c) {
  
  let jumps = 0;
  let i = 0;
  let end = c.length - 1;

  while (i < c.length) {

    //move once or twice
    c[i+2] != 1 ? i+=2 : i++;

    jumps++;


    if(i === end){
      console.log(`i: ${i} Done !: c[${i}] -> c[${i+2}]`);
      break;
    }
  }

  document.getElementById("jumps").innerHTML = `jumps: ${jumps}`;
  return jumps;
}

/*
const ar = [0, 0, 1, 0, 0, 1, 0];
const n = ar.length;

document.getElementById("ar").innerHTML = `ar: ${ar}`;
document.getElementById("n").innerHTML = `n: ${n}`;
document.getElementById("expected").innerHTML = `expected: ${4}`;

jumpingOnClouds(ar);
*/