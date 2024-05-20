let preco, pagamento;

preco = parseFloat(prompt("Informe o preço do produto"));
pagamento = prompt("Informe a forma de pagamento: 1 para à vista | 2 para à prazo");
vendaArrow(preco, pagamento);


const vendaArrow = (preco, pagamento) => {
    if(pagamento == 1){
        preco = preco - (preco*0.05);
        console.log("Preço à vista: "+ preco);
    }
    if(pagamento == 2){
        preco = preco + (preco*0.1);
        console.log("Preço à prazo: "+ preco);
    }
}
