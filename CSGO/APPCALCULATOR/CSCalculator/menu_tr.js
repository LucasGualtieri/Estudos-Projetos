$(document).ready(function () {
	$.getJSON("./items.json", function (items) {
		// console.log(items);

		//console.log(typeof(minNextRound))
		//Declaração de Variáveis "Globais":

		var budget = 0;
		var preco = 0;
		var granadasCount = 0;
		var nades = ["bang1", "bang", "smoke", "he", "molotov"];

		//LINK Disponibilidade
		function disponibilidade() {
			$("#lblBudgetValor").text("R$ " + budget);
			$("#lblPrecoValor").text("R$ " + preco);

			function AddEnabledClass(item) {
				$(item.btnId).removeAttr("disabled");
				$(item.btnId).removeClass("btn-disabled");
				$(item.btnId).addClass("btn-enabled");
			}

			function disabled(item) {
				$(item.btnId).attr("disabled", "disabled");
				$(item.btnId).removeClass("btn-enabled");
				$(item.btnId).addClass("btn-disabled");
			}

			function checkNadeCount() {
				// console.log(granadasCount);
				if (granadasCount == 4) {
					nades.every((nade) => {
						if (!items[nade].isEnabled) {
							disabled(items[nade]);
							return false;
						}
						return true;
					});
				}
			}

			for (let item in items) {
				let currentItem = items[item];
				if (budget < currentItem.price && !currentItem.isEnabled) {
					disabled(currentItem);
				} else if (budget >= currentItem.price && !currentItem.isEnabled) {
					AddEnabledClass(currentItem);
					checkNadeCount();
				}
			}

			// if (items[9].isEnabled) { //if (vestHelm)
			//    enabled(8)
			// } else if (items[8].isEnabled && budget >= 350) { //if (vest)
			//    enabled(9)
			// }
		}

		// -----------------------------------------------------------------------------------------

		function btnVestHelmBuy(item) {
			if (item.btnId == "#btnVestHelm" && items.vest.isEnabled) {
				items[8].isEnabled = false;
				budget += 650;
				preco -= 650;
				$("#btnVest").removeClass("btn-bought").addClass("btn-enabled");
			} else if (item.btnId == "#btnVest" && items.vestHelm.isEnabled) {
				items.vest.isEnabled = false;
				budget += 1000;
				preco -= 1000;
				$("#btnVestHelm").removeClass("btn-bought").addClass("btn-enabled");
			}
		}

		// -----------------------------------------------------------------------------------------

		//LINK Botão de compra: Todas as armas
		$("button").click(function () {
			const id = "#" + this.id;
			// let i = 0; i < items.length; i++
			for (let item in items) {
				let currentItem = items[item];
				if (id == currentItem.btnId) {
					if (!currentItem.isEnabled) {
						currentItem.isEnabled = true;
						budget -= currentItem.price;
						preco += currentItem.price;

						btnVestHelmBuy(currentItem);
						$(currentItem.btnId).removeClass("btn-enabled");
						$(currentItem.btnId).addClass("btn-bought");

						for (let nade of nades) {
							if (items[nade].isEnabled) {
								granadasCount++;
								break;
							}
						}
					} else {
						currentItem.isEnabled = false;
						budget += currentItem.price;
						preco -= currentItem.price;
						$(currentItem.btnId).removeClass("btn-bought");
						$(currentItem.btnId).addClass("btn-enabled");

						for (let nade of nades) {
							if (!items[nade].isEnabled) {
								granadasCount--;
								break;
							}
						}
					}
					disponibilidade();
					break;
				}
			}
		});

		// -----------------------------------------------------------------------------------------

		//LINK Listener do input do usuario
		$("#txtbxGrana").on("input", function () {
			budget = parseInt($("#txtbxGrana").val());
			if (budget > 16000) {
				$("#txtbxGrana").val(16000);
				budget = 16000;
			} else if (isNaN(budget)) {
				//isNaN() retorna True se variável não é um número
				budget = 0;
			}
			disponibilidade();
		});

		// -----------------------------------------------------------------------------------------

		$("#btnReload").click(function () {
			location.reload(true);
		}); //Tenho que fazer um btnReload que não reloada a página, mas sim reseta as variaveis e etc etc

		// -----------------------------------------------------------------------------------------

		//LINK Botão Copy Paste
		$("#btnCopy").click(function () {
			// const btnCopy = document.getElementById("btnCopy")
			const dummyTextarea = document.getElementById("dummyTextarea");
			let copyPaste = "";
			for (let i = 0; i < items.length; i++) {
				if (items[i].isEnabled == true) {
					copyPaste += items[i].conslComm + "; ";
				}

				$("#dummyTextarea").val(copyPaste);
				dummyTextarea.select();
				document.execCommand("copy");
			}
		});

		// -----------------------------------------------------------------------------------------

		/*
			//LINK Botão Loss Bonus
			$("#btnLossBonus").click(function () {
				arrayLossBonus[0]++;
				minNextRound[0] += 500;
				minNextRound[1] += 500;
				arrayLossBonus[1] += 500;

				if (arrayLossBonus[0] == 5) {
					arrayLossBonus[0] = 0;
					arrayLossBonus[1] = 1400;
					minNextRound[0] -= 2500;
					minNextRound[1] -= 2500;
					$("#lblLossBonusValue").text(arrayLossBonus);
					$("#lblMinNextRoundValue").text(minNextRound);
				}

				$("#lblLossBonusValue").text(arrayLossBonus[0]);
				$("#lblLossBonusValue1").text(arrayLossBonus[1]);
				$("#lblMinNextRoundValue").text(minNextRound[0]);

				// Disponibilidade();
			});
		*/

		//LINK Botão de Teste
		$("#btnTeste").click(function () {});
	});
});
