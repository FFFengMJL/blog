function initial () {
    // test = "▼";
    test = $("<span class = \"sort\"><span>").text("▲");
    // $("th").append($("<span class = \"sort\"><span>").text("▲"));
    $("th").append(test);
    $("th").data("mode", 0);
    $(".sort").hide();
}

function addLis() {
    $("th").click(function() {
        if ($(this).data("mode") == 0) sortBack($(this));
        switch ($(this).data("mode")) {
            case 0: $(this).children(".sort").show(0, sortAsend($(this)));break;
            case 1: sortDesend($(this));break;
            case 2: sortAsend($(this));break;
        }    
    })
}

function getList(obj) {
    var trList = [];
    $(obj.parents("table").children("tbody").children("tr")).each(function() {
        var tdList = [];
        $(this).children("td").each(function() {
            tdList[$(this).index()] = $(this).html();
        });
        trList.push(tdList);
    });
    return trList;
}

function rebuild(obj, tarList) {
    obj.parents("table").children("tbody").empty();
    for (var i = 0; i < tarList.length; i++) {
        var tr = $("<tr></tr>").text("");
        for (var j = 0; j < tarList[i].length; j++) {
            var td = $("<td></td>").text(tarList[i][j]);
            tr.append(td);
        }
        obj.parents("table").children("tbody").append(tr);
    }
}

function sortAsend(obj) { // 正序排列
    obj.data("mode", 1);
    obj.children(".sort").text("▲");
    obj.addClass("focus");
    var tarList = _.sortBy(getList(obj), function(tar) {return tar[obj.index()]});
    rebuild(obj, tarList);
}

function sortDesend(obj) { // 倒叙排列
    obj.data("mode", 2);
    obj.children(".sort").text("▼");
    var tarList = _.sortBy(getList(obj), function(tar) {return tar[obj.index()]}).reverse();
    rebuild(obj, tarList);
}

function sortBack(obj) { // 清除其他的排序标志
    // obj.parent().children("th").data("mode", 0);
    // obj.parent().children("th").children(".sort").hide();
    // obj.parent().children("th").removeClass("focus");
    obj.siblings().data("mode", 0);
    obj.siblings().children(".sort").hide();
    obj.siblings().removeClass("focus");
    // for (var i = 0; i < obj.prevAll().length; i++) {
    //     $(obj.prevAll()[i]).data("mode", 0);
    //     $(obj.prevAll()[i]).children(".sort").hide();
    // }
}

function main() {
    initial();
    addLis();
}

$(document).ready(function() {
    main();
});

