<?php
/*
	验证码类：
*/
class ValidateCode
{
	private $charset = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789';
	private $code;
	private $len = 4;
	private $width = 130;
	private $height = 50;
	private $img_handle;
	private $font;
	private $font_size = 20;
	private $font_color;
	
	public function __construct()
	{
		$this->font = dirname(__FILE__).'/font/elephant.ttf';
	}
	
	private function createCode()
	{
		// 生成验证码
		$this->code = substr(str_shuffle($this->charset), 0, $this->len);
	}
	
	private function createBackground()
	{
		$this->img_handle = imagecreatetruecolor($this->width, $this->height);
		$color = imagecolorallocate($this->img_handle, mt_rand(157, 255), mt_rand(157, 255), mt_rand(157, 255));
		imagefilledrectangle($this->img_handle, 0, $this->height, $this->width, 0, $color);
	}
	
	private function createWords()
	{
		$x = $this->width / $this->len;
		for ($i = 0; $i < $this->len; $i++)
		{
			$this->font_color = imagecolorallocate($this->img_handle, mt_rand(0, 156), mt_rand(0, 156), mt_rand(0, 156));
			imagettftext($this->img, $this->fontsize, mt_rand(-30, 30), $x*$i+mt_rand(1, 5), $this->height/1.4, $this->font_color, $this->font, $this->code[$i]);
		}
	}
	
	private function createBarriers()
	{
		// line
		for ($i = 0; $i < 6; $i++)
		{
			$color = imagecolorallocate($this->img_handle, mt_rand(0, 156), mt_rand(0, 156), mt_rand(0, 156));
			imageline($this->img_handle, mt_rand(0, $this->width), mt_rand(0, $this->height), mt_rand(0, $this->width), mt_rand(0, $this->height), $color);
		}
		
		// snow
		for ($i = 0; $i < 100; $i++)
		{
			$color = imagecolorallocate($this->img_handle, mt_rand(200, 255), mt_rand(200, 255), mt_rand(200, 255));
			imagestring($this->img_handle, mt_rand(1, 5), mt_rand(0, $this->width), mt_rand(0, $this->height), '*', $color);
		}
	}
	
	private function outputImg()
	{
		header('Content-type: image/png');
		imagepng($this->img_handle);
		imagedestroy($this->img_handle);
	}
	
	public function createImg()
	{
		$this->createBackground();
		$this->createCode();
		$this->createBarriers();
		$this->createWords();
		$this->outputImg();
	}
	
	public function getCode()
	{
		return strtolower($this->code);
	}
}

?>