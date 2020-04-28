function solution(array, commands) {
    var answer = [];
    for(var i = 0 ; i < commands.length ; i++){
        var sliced = array.slice(commands[i][0]-1,commands[i][1]);
        sliced.sort(function(a,b){
            return a - b;
        });
        answer.push(sliced[commands[i][2]-1]);
    }
    return answer;
}