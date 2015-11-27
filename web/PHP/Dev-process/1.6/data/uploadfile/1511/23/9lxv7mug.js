function addListener(dom, str, fn, b) {
	window.addEventListener ? (dom || window).addEventListener(str, fn, b || false) : (dom || window).attachEvent('on' + str, fn);
}

function getByClass(str, obj) {
	str = str || '.';
	obj = obj || document;
	if (str === '' + str && str.match(/^[\w\*-]+$/g)) {
		var arr = [],
			arrObj = obj.getElementsByTagName('*'),
			regExp = eval('/(?:\\s|^)' + str + '(?:\\s|$)/ig');
		for (var i = 0; i < arrObj.length; i++)
			if (arrObj[i].className.match(regExp)) arr.push(arrObj[i]);
	}
	return arr && arr.length ? arr : null;
}

function navtoggle() {
	console.log('OK')
	var arr = getByClass('item');
	for (var i = arr.length - 1; i >= 0; i--) {
		addListener(arr[i], 'mouseover', fn1);
		addListener(arr[i], 'mouseout', fn2);
	}

	function fn2() {
		document.body.style.marginTop = 0;
	}

	function fn1() {
		document.body.style.marginTop = '90px';
	}
}
addListener(null, 'load', navtoggle);
