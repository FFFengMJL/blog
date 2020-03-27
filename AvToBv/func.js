// import {dec, enc} from "./code.js"

if (typeof $ === "undefined") {
    var flag = 0,a = document.createElement("script"), b = document.createElement("script");
    a.src = "https://cdnjs.cloudflare.com/ajax/libs/jquery/2.1.0/jquery.js";
    document.body.appendChild(a);
    b.src = "https://cdnjs.cloudflare.com/ajax/libs/lodash.js/3.10.1/lodash.js";document.body.appendChild(b);
    a.onload = b.onload = () => {
        flag++;
        if (flag == 2) main();
    }
}

const table='fZodR9XQDSUm21yCkr6zBqiveYah8bt4xsWpHnJE7jL5VG3guMTKNPAwcF';
let tr={};
for (let i = 0; i < 58; i++) {
	tr[table[i]]=i;
}
const s=[11,10,3,8,4,6];
const xor=177451812;
const add=8728348608;

function dec(x) {
	let r=0;
	for (let i = 0; i < 6; i++)
		r+=tr[x[s[i]]]*58**i;
	return (r-add)^xor;
}

function enc(x) {
    let res = '';
	x=(x^xor)+add;
	let r=['B', 'V', '1', ' ', ' ', '4', ' ', '1', ' ', '7', ' ', ' '];
	for (let i = 0; i < 6; i++) {
        r[s[i]]=table[Math.floor(x/58**i)%58];
    }
        
	return r.join('');
}

function main() {
    const avRule = /\d{6,}/;
    const avRuleWithAV = /^av\d{6,}/;
    const bvRule = /^BV1\w{2}4\w{3}7\w{2}/;
    // let code = await import('./code');
    let avLast = '', bvLast = '';
    $("#av").on('blur', function() {
        let av = $(this).val();
        if (!$(this).val()) return;
        else if (!avRule.test(av)) { // 第一种情况
            if (!avRuleWithAV.test(av)) { // 第二种情况
                $("#bv").val("请输入正确的av号");
                return;
            }
            av = av.substr(2);
        }
        console.log(av);
        av = parseInt(av);
        $("#bv").val(enc(av));
    });

    $('#bv').on('blur', function() {
        if (!$(this).val()) return;
        else if (!bvRule.test($(this).val())) {
            $('#av').val('请输入正确的bv号');
            return ;
        }
        let bv = $(this).val();
        $('#av').val(`av${dec(bv)}`);
    });
}