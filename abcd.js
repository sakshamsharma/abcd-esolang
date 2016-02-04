abcd = function(program, input, outputElem) {
  var Position = 0;

  var Character = '';
  var Program = program;
  var input = input;
  var readInput = 0;

  var Register1 = 0;
  var Register2 = 0;
  var Register3 = 0;
  var Register4 = [0,0];
  var Mode = 0;
  var Memory = [];
  var Temp = 0;
  var finished = 0;
  var iter = 0;

  function inputFxn(regNum) {

    if(readInput < input.length) {
      Temp = input.charCodeAt(readInput);
      
      if(regNum === 1) {
        Register1 = Temp;
      } else {
        Register2 = Temp;
      }
    }
    readInput++;
    
  }

  outputElem.innerHTML = "";
  while(Position < Program.length) {

    switch(Program[Position]) {
    case "a":
      Register1 += 1;
      break;
    case "b":
      Register1 -= 1;
      break;
    case "c":
      Register1 += 10;
      break;
    case "d":
      Register1 -= 10;
      break;
    case "e":
      Register1 += 100;
      break;
    case "f":
      Register1 -= 100;
      break;
    case "g":
      Register2 += 1;
      break;
    case "h":
      Register2 -= 1;
      break;
    case "i":
      Register2 += 10;
      break;
    case "j":
      Register2 -= 10;
      break;
    case "k":
      Register2 += 100;
      break;
    case "l":
      Register2 -= 100;
      break;
    case "m":
      Register3 = !Register1;
      break;
    case "n":
      Register3 = !Register2;
      break;
    case "o":
      Register3 = Register1 & Register2;
      break;
    case "p":
      Register3 = Register1 | Register2;
      break;
    case "q":
      Register3 = Register1 ^ Register2;
      break;
    case "r":
      Register3 = Register1 + Register2;
      break;
    case "s":
      Register3 = Register1 - Register2;
      break;
    case "t":
      Register3 = Register1 * Register2;
      break;
    case "u":
      Register3 = Register1 / Register2;
      break;
    case "v":
      Register3 = Register1 % Register2;
      break;
    case "w":
      Register3 = Register1 ^ Register2;
      break;
    case "x":
      Register1 = 0;
      break;
    case "y":
      Register2 = 0;
      break;
    case "z":
      Register3 = 0;
      break;
    case "A":
      Register2 = Register1;
      break;
    case "B":
      Register1 = Register2;
      break;
    case "C":
      Register3 = Register1;
      break;
    case "D":
      Register3 = Register2;
      break;
    case "E":
      Register1 = Register3;
      break;
    case "F":
      Register2 = Register3;
      break;
    case "G":
      Register1 = Memory[Register4[0]];
      break;
    case "H":
      Register2 = Memory[Register4[0]];
      break;
    case "I":
      Memory[Register4[0]] = Register3;
      break;
    case "J":
      inputFxn(1);
      break;
    case "K":
      inputFxn(2);
      break;
    case "L":
      outputElem.innerHTML =
        outputElem.innerHTML + (String.fromCharCode(Register3));
      break;
    case "M":
      outputElem.innerHTML =
        outputElem.innerHTML + Register3;
      break;
    case "N":
      if(Register1 === Register2) Position = Register4[1]-1;
      break;
    case "O":
      if(Register1 !== Register2) Position = Register4[1]-1;
      break;
    case "P":
      if(Register1 >= Register2) Position = Register4[1]-1;
      break;
    case "Q":
      if(Register1 <= Register2) Position = Register4[1]-1;
      break;
    case "R":
      if(Register3) Position = Register4[1]-1;
      break;
    case "S":
      Register4[Mode] += 1;
      break;
    case "T":
      Register4[Mode] -= 1;
      break;
    case "U":
      Register4[Mode] += 10;
      break;
    case "V":
      Register4[Mode] -= 10;
      break;
    case "W":
      Register4[Mode] += 100;
      break;
    case "X":
      Register4[Mode] -= 100;
      break;
    case "Y":
      Register4[Mode] = 0;
      break;
    case "Z":
      Mode = (Mode+1)%2;
      break;
    case "?":
      if(readInput >= input.length + 1)
        finished=1;
      break;
    }

    if(finished || iter > 2000)
      break;
    Position++;
  }
}

run = function() {
  prog = document.getElementById("program").value;
  inpt = document.getElementById("input").value;
  output = document.getElementById("output");
  abcd(prog, inpt, output);
}
