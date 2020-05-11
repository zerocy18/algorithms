function solution(arr) {
    var answer = 0;
    answer = lcm(arr[0],arr[1]);
    for(var i = 2 ; i < arr.length; i++){
        answer = lcm(answer, arr[i]);
    }
    return answer;
}
function gcd(a, b){
    while(b>0){
        var temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

function lcm(a,b){
    return a*b / gcd(a,b);
}

console.log(solution([1,2,3]));