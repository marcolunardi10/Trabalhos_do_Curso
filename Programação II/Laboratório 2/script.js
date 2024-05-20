let botao = document.getElementById("tema");
let body = document.body;

botao.addEventListener("click", function(){
    if (getComputedStyle(body).backgroundColor === "rgb(33, 34, 34)"){
        body.style.backgroundColor = "white";
        body.style.color = "black";
    }else{
        body.style.backgroundColor = "rgb(33, 34, 34)";
        body.style.color = "white";
    }
});

let btnCC = document.getElementById("cc");
let btnFilo = document.getElementById("filosofia");
let divcc = document.getElementById("divcc");
let divFilo = document.getElementById("divfilo");

btnCC.addEventListener("click", function(){
        divcc.style.display = "block";
        divFilo.style.display = "none";
});

btnFilo.addEventListener("click", function(){
    divcc.style.display = "none";
    divFilo.style.display = "block";
});