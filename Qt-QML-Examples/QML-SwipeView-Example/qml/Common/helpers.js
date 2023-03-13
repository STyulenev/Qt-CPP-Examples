var arr = [ 'Male', 'Female', 'Unknown' ];

function getSexList() {
    return arr;
}

function getSex(id) {
    console.log("00000000000  id " + id)
    if (id >= 0 && id < arr.length)
        return arr[id];
    else
        return "Unknown";
}
