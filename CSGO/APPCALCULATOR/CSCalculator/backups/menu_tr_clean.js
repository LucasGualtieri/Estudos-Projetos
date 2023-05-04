$(document).ready(function() {
    //console.log(typeof(minNextRound))
    //Declaração de Variáveis "Globais":
    let budget = 0
    let preco = 0
    
    const items = [
        {isEnabled:false, price:200, stringBtn:"btnBang1", btnName:btnBang1, consoleCommand:"buy flashbang"}, //......Bang1 0
        {isEnabled:false, price:200, stringBtn:"btnBang", btnName:btnBang, consoleCommand:"buy flashbang"}, //.......Bang 1
        {isEnabled:false, price:300, stringBtn:"btnSmoke", btnName:btnSmoke, consoleCommand:"buy smokegrenade"}, //...Smoke 2
        {isEnabled:false, price:300, stringBtn:"btnHe", btnName:btnHe, consoleCommand:"buy hegrenade"}, //............He 3
        {isEnabled:false, price:400, stringBtn:"btnMolotov", btnName:btnMolotov, consoleCommand:"buy molotov"}, //....Molotov 4
        {isEnabled:false, price:300, stringBtn:"btnP250", btnName:btnP250, consoleCommand:"buy p250"}, //.............P250 5
        {isEnabled:false, price:500, stringBtn:"btnTec9", btnName:btnTec9, consoleCommand:"buy fn57"}, //.............Tec9 6
        {isEnabled:false, price:700, stringBtn:"btnDeagle", btnName:btnDeagle, consoleCommand:"buy deagle"}, //.......Dagle 7
        {isEnabled:false, price:650, stringBtn:"btnVest", btnName:btnVest, consoleCommand:"buy vest"}, //.............Vest 8
        {isEnabled:false, price:1000, stringBtn:"btnVestHelm", btnName:btnVestHelm, consoleCommand:"buy vesthelm"}, //VestHelm 9
        {isEnabled:false, price:1050, stringBtn:"btnMac10", btnName:btnMac10, consoleCommand:"buy mac10"}, //.........Mac10 10
        {isEnabled:false, price:1200, stringBtn:"btnUmp", btnName:btnUmp, consoleCommand:"buy ump45"}, //.............Ump 11
        {isEnabled:false, price:1800, stringBtn:"btnGalil", btnName:btnGalil, consoleCommand:"buy galilar"}, //.......Galil 12
        {isEnabled:false, price:2700, stringBtn:"btnAk", btnName:btnAk, consoleCommand:"buy ak47"}, //................Ak47 13
        {isEnabled:false, price:3000, stringBtn:"btnKrieg", btnName:btnKrieg, consoleCommand:"buy sg556"}, //.........Krieg 14
        {isEnabled:false, price:1700, stringBtn:"btnScout", btnName:btnScout, consoleCommand:"buy ssg08"}, //.........Scout 15
        {isEnabled:false, price:4750, stringBtn:"btnAwp", btnName:btnAwp, consoleCommand:"buy awp"} //................Awp 16
    ];
    
    let numberOfItens = items.length;

    //LINK Disponibilidade
    function disponibilidade () {
        $("#lblBudgetValor").text("R$ " + budget)
        $("#lblPrecoValor").text("R$ " + preco)

        function enabled (arrayPosition) {
            $(items[arrayPosition].btnName).removeAttr("disabled")
            $(items[arrayPosition].btnName).removeClass('btn-disabled')
            $(items[arrayPosition].btnName).addClass('btn-enabled')
        }

        function disabled (arrayPosition) {
            $(items[arrayPosition].btnName).attr("disabled", "disabled")
            $(items[arrayPosition].btnName).removeClass('btn-enabled')
            $(items[arrayPosition].btnName).addClass('btn-disabled')
        }

        for (loop = 0; loop < numberOfItens; loop++)
        {
            if (budget < items[loop].price && items[loop].isEnabled != true) {
                disabled(loop)
            } else if (budget >= items[loop].price && items[loop].isEnabled != true) {
                enabled(loop)
            }
        }
    }

    //LINK Botão de compra: Todas as armas
    const arrayBtnName = [items[0].btnName, items[1].btnName, items[2].btnName, items[3].btnName, items[4].btnName, items[5].btnName, items[6].btnName, items[7].btnName, items[8].btnName, items[9].btnName, items[10].btnName, items[11].btnName, items[12].btnName, items[13].btnName, items[14].btnName, items[15].btnName, items[16].btnName]
    $(arrayBtnName).click(function() {
        const id = this.id
        for (loop = 0; loop < numberOfItens; loop++) {
            if (id == items[loop].stringBtn) {

                if (!items[loop].isEnabled) {
                    items[loop].isEnabled = true
                    budget -= items[loop].price
                    preco += items[loop].price
                    $(items[loop].btnName).removeClass('btn-enabled').addClass('btn-bought')
                } else {
                    items[loop].isEnabled = false
                    budget += items[loop].price
                    preco -= items[loop].price
                    $(items[loop].btnName).removeClass('btn-bought').addClass('btn-enabled')
                }
                disponibilidade()
                break
            }
        }
    })

    //LINK Listener do input do usuario
    $('#txtbxGrana').on('input', function () {
        budget = parseInt($('#txtbxGrana').val())
        if (budget > 16000) {
            $('#txtbxGrana').val(16000)
            budget = 16000
        } else if (isNaN(budget)) { //isNaN() retorna True se variável não é um número
            budget = 0
        }
        disponibilidade()
    })

    $("#btnReload").click(function() { location.reload(true) }) //Tenho que fazer um btnReload que não reload a página, mas sim reseta as variaveis

    //LINK Botão Copy Paste
    // const btnCopy = document.getElementById("btnCopy")
    const dummyTextarea = document.getElementById("dummyTextarea")
    $('#btnCopy').click(function() {
        let copyPaste = "";
        for (loop = 0; loop < numberOfItens; loop++) {
            if (arrayArmas[loop] == true) {
                copyPaste += arrayBtnNameString[loop] + "; "
            }

            $("#dummyTextarea").val(copyPaste)
            dummyTextarea.select()
            document.execCommand('copy')
        }
    })

})