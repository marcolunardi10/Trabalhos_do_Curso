
$("#btnCC").on("click", function(){
    $("#container-cc").css("display", "block");
    $("#container-fil").css("display", "none");
});

$("#btnFil").on("click", function(){
    $("#container-cc").css("display", "none");
    $("#container-fil").css("display", "block");
});


$("#botao-tema").on("click", function(){
    var corAtual = $("body").css("background-color");

    if (corAtual === "rgb(255, 255, 255)") {
        $("body").css("background-color", "rgb(35, 41, 57)");
        $("body").css("color", "white");
        $("#botao-tema").text("Claro");
        $("#botao-tema").toggleClass("btn-dark btn-light");
        $("h2 span").removeClass("bg-light text-dark").addClass("bg-dark text-light");
        $("h1 span").removeClass("bg-light text-dark").addClass("bg-dark text-light");
    } else {
        $("body").css("background-color", "white");
        $("body").css("color", "black");
        $("#botao-tema").text("Escuro");
        $("#botao-tema").toggleClass("btn-light btn-dark");
        $("h2 span").removeClass("bg-dark text-light").addClass("bg-light text-dark");
        $("h1 span").removeClass("bg-dark text-light").addClass("bg-light text-dark");
    }
});