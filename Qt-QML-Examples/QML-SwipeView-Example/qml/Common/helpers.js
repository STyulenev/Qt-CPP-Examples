var arr = [ 'Male', 'Female', 'Unknown' ];

function getSexList() {
    return arr;
}

function getSex(id) {
    if (id >= 0 && id < arr.length)
        return arr[id];
    else
        return "Unknown";
}
