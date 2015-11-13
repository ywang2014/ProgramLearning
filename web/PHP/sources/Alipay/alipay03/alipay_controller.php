<?php if ( ! defined('BASEPATH')) exit('No direct script access allowed');
/**
 * alipy支付接口
 * @author onwulc@163.com
 *
 */
class Alipay extends CI_Controller {
    private $alipay_config;
    function __construct(){
        parent::__construct();
        $this->_init_config();
        $this->load->helper('url');
    }
 
    function index(){
        $this->load->view('alipay');//装载支付视图页面，post到do_alipay
    }
 
    function do_alipay(){
        require_once(APPPATH.'third_party/alipay/alipay_submit.class.php');
        //构造要请求的参数数组，无需改动
        $parameter = array(
            "service" => "create_direct_pay_by_user",
            "partner" => trim($this->alipay_config['partner']),
            "payment_type"    => '1',
            "notify_url"    => site_url('alipay/do_notify'),
            "return_url"    => site_url('alipay/do_return'),
            "seller_email"    => trim($this->alipay_config['seller_emaill']),//支付宝帐户,
            "out_trade_no"    => $this->input->post('WIDout_trade_no'),//商户订单号
            "subject"    => $this->input->post('WIDsubject'),//订单名称
            "total_fee"    => $this->input->post('WIDtotal_fee'),//必填,付款金额
            "body"    => $this->input->post('WIDbody'),//必填,订单描述
            "show_url"    => $this->input->post('WIDshow_url'),//商品展示地址
            "anti_phishing_key"    => '',//防钓鱼时间戳
            "exter_invoke_ip"    => '',//客户端的IP地址
            "_input_charset"    => trim(strtolower($this->alipay_config['input_charset']))
        );
 
        //建立请求
        $alipaySubmit = new AlipaySubmit($this->alipay_config);
        $html_text = $alipaySubmit->buildRequestForm($parameter,"get", "确认");
        echo $html_text;
    }
 
    function do_notify(){
        require_once(APPPATH.'third_party/alipay/alipay_notify.class.php');
 
    }
 
    function do_return(){
        require_once(APPPATH.'third_party/alipay/alipay_notify.class.php');
        $alipayNotify = new AlipayNotify($this->alipay_config);
        $verify_result = $alipayNotify->verifyReturn();
        
        //商户订单号
        $out_trade_no = $_GET['out_trade_no'];
 
        //支付宝交易号
        $trade_no = $_GET['trade_no'];
 
        //交易状态
        $trade_status = $_GET['trade_status'];
 
 
        if($_GET['trade_status'] == 'TRADE_FINISHED' || $_GET['trade_status'] == 'TRADE_SUCCESS') {
            //判断该笔订单是否在商户网站中已经做过处理
            //如果没有做过处理，根据订单号（out_trade_no）在商户网站的订单系统中查到该笔订单的详细，并执行商户的业务程序
            //如果有做过处理，不执行商户的业务程序
            echo '支付成功，交易处理环节';
        }else {
            echo "trade_status=".$_GET['trade_status'];
        }
 
        echo "验证成功<br />";
 
    }
 
    /**
     * 初始化支付宝配置，详细参数请根据自己实际接口修改
     */
    private function _init_config(){
        //支付宝帐户
        $alipay_config['seller_emaill'] = ''; 
        
        //合作身份者id，以2088开头的16位纯数字
        $alipay_config['partner'] = '2088999999999999';
        
        
        //安全检验码，以数字和字母组成的32位字符
        $alipay_config['key'] = 'vhyjvdht3ayxbtx692vlkbwilhXXXXXX';
 
        //签名方式 不需修改
        $alipay_config['sign_type'] = strtoupper('MD5');
 
        //字符编码格式 目前支持 gbk 或 utf-8
        $alipay_config['input_charset'] = strtolower('utf-8');
 
        //ca证书路径地址，用于curl中ssl校验
        //请保证cacert.pem文件在当前文件夹目录中
        $alipay_config['cacert'] = APPPATH.'third_party/alipay/cacert.pem';
 
        //访问模式,根据自己的服务器是否支持ssl访问，若支持请选择https；若不支持请选择http
        $alipay_config['transport'] = 'http';
 
        $this->alipay_config = $alipay_config;
    }
}
?>