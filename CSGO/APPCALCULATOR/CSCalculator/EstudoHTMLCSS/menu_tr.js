$(document).ready(function () {
   //console.log(typeof(minNextRound))
   //Declaração de Variáveis "Globais":
   const items = [
     { isEnabled: false, price: 200, stringBtn: "btnBang1", btnName: btnBang1, consoleCommand: "buy flashbang" }, //......Bang1 0
     { isEnabled: false, price: 200, stringBtn: "btnBang", btnName: btnBang, consoleCommand: "buy flashbang" }, //.......Bang 1
     { isEnabled: false, price: 300, stringBtn: "btnSmoke", btnName: btnSmoke, consoleCommand: "buy smokegrenade" }, //...Smoke 2
     { isEnabled: false, price: 300, stringBtn: "btnHe", btnName: btnHe, consoleCommand: "buy hegrenade" }, //............He 3
     { isEnabled: false, price: 400, stringBtn: "btnMolotov", btnName: btnMolotov, consoleCommand: "buy molotov" }, //....Molotov 4
     { isEnabled: false, price: 300, stringBtn: "btnP250", btnName: btnP250, consoleCommand: "buy p250" }, //.............P250 5
     { isEnabled: false, price: 500, stringBtn: "btnTec9", btnName: btnTec9, consoleCommand: "buy fn57" }, //.............Tec9 6
     { isEnabled: false, price: 700, stringBtn: "btnDeagle", btnName: btnDeagle, consoleCommand: "buy deagle" }, //.......Dagle 7
     { isEnabled: false, price: 650, stringBtn: "btnVest", btnName: btnVest, consoleCommand: "buy vest" }, //.............Vest 8
     { isEnabled: false, price: 1000, stringBtn: "btnVestHelm", btnName: btnVestHelm, consoleCommand: "buy vesthelm" }, //VestHelm 9
     { isEnabled: false, price: 1050, stringBtn: "btnMac10", btnName: btnMac10, consoleCommand: "buy mac10" }, //.........Mac10 10
     { isEnabled: false, price: 1200, stringBtn: "btnUmp", btnName: btnUmp, consoleCommand: "buy ump45" }, //.............Ump 11
     { isEnabled: false, price: 1800, stringBtn: "btnGalil", btnName: btnGalil, consoleCommand: "buy galilar" }, //.......Galil 12
     { isEnabled: false, price: 2700, stringBtn: "btnAk", btnName: btnAk, consoleCommand: "buy ak47" }, //................Ak47 13
     { isEnabled: false, price: 3000, stringBtn: "btnKrieg", btnName: btnKrieg, consoleCommand: "buy sg556" }, //.........Krieg 14
     { isEnabled: false, price: 1700, stringBtn: "btnScout", btnName: btnScout, consoleCommand: "buy ssg08" }, //.........Scout 15
     { isEnabled: false, price: 4750, stringBtn: "btnAwp", btnName: btnAwp, consoleCommand: "buy awp" } //................Awp 16
   ]

   let budget = 0
   let preco = 0
   let granadas = 0
   let numberOfItens = items.length

   //LINK Disponibilidade
   function disponibilidade() {

      $("#lblBudgetValor").text("R$ " + budget)
      $("#lblPrecoValor").text("R$ " + preco)

      function enabled(arrayPosition) {
         $(items[arrayPosition].btnName).removeAttr("disabled")
         $(items[arrayPosition].btnName).removeClass('btn-disabled')
         $(items[arrayPosition].btnName).addClass('btn-enabled')
      }

      function disabled(arrayPosition) {
         $(items[arrayPosition].btnName).attr("disabled", "disabled")
         $(items[arrayPosition].btnName).removeClass('btn-enabled')
         $(items[arrayPosition].btnName).addClass('btn-disabled')
      }

      for (loop = 0; loop < numberOfItens; loop++) {
         if (budget < items[loop].price && items[loop].isEnabled != true) {
            disabled(loop)
         } else if (budget >= items[loop].price && items[loop].isEnabled != true) {
            if (granadas == 4 && loop < 5) {
                  for (loop = 0; loop < 5; loop++) {
                     if (!items[loop].isEnabled) {
                        disabled(loop)
                        break
                     }
                  }
            } else {
                  enabled(loop)
            }
         }
      }

      if (items[9].isEnabled) { //if (vestHelm)
         enabled(8)
      } else if (items[8].isEnabled && budget >= 350) { //if (vest)
         enabled(9)
      }
   }

   function btnVestHelmBuy(arrayItem) {
      if (arrayItem == 9 && items[8].isEnabled) {
         items[8].isEnabled = false
         budget += 650
         preco -= 650
         $('#btnVest').removeClass('btn-bought').addClass('btn-enabled')
      } else if (arrayItem == 8 && items[9].isEnabled) {
         items[9].isEnabled = false
         budget += 1000
         preco -= 1000
         $('#btnVestHelm').removeClass('btn-bought').addClass('btn-enabled')
      }
   }

   //LINK Botão de compra: Todas as armas
   const arrayBtnName = [btnBang1, btnBang, btnSmoke, btnHe, btnMolotov, btnP250, btnTec9, btnDeagle, btnVest, btnVestHelm, btnMac10, btnUmp, btnGalil, btnAk, btnKrieg, btnScout, btnAwp]
   $(arrayBtnName).click(function () {
      const id = this.id
      for (loop = 0; loop < numberOfItens; loop++) {
         if (id == items[loop].stringBtn) {
            if (!items[loop].isEnabled) {
               items[loop].isEnabled = true
               budget -= items[loop].price
               preco += items[loop].price
               if (loop < 5) granadas++
               btnVestHelmBuy(loop)
               $(items[loop].btnName).removeClass('btn-enabled').addClass('btn-bought')
            }
            else {
               items[loop].isEnabled = false
               budget += items[loop].price
               preco -= items[loop].price
               if (loop < 5) granadas--
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

   $("#btnReload").click(function () { location.reload(true) }) //Tenho que fazer um btnReload que não reloada a página, mas sim reseta as variaveis e etc etc

   //LINK Botão Copy Paste
   $('#btnCopy').click(function () {
      // const btnCopy = document.getElementById("btnCopy")
      const dummyTextarea = document.getElementById("dummyTextarea")
      let copyPaste = ""
      for (loop = 0; loop < numberOfItens; loop++) {
         if (items[loop].isEnabled == true) {
            copyPaste += items[loop].consoleCommand + "; "
         }

         $("#dummyTextarea").val(copyPaste)
         dummyTextarea.select()
         document.execCommand('copy')
      }
   })

   //LINK Botão de Teste
   $('#btnTeste').click(function () {

   })

})