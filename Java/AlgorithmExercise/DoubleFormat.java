import java.math.BigDecimal;
import java.math.RoundingMode;
import java.text.DecimalFormat;

/**
 * 对Double值保留两位小数的方法总结
 * 
 * @author Administrator
 *
 */
public class DoubleFormat {
	public static void main(String[] args){
		DoubleFormat df = new DoubleFormat();
		System.out.println(df.formatMethodByRound(111.2212342));
	}

	//最简洁，利用类型转型转换
	public Double formatMethodByRound(Double value){
		return Math.round(value * 100) / 100.0;
	}
	
	// 利用大数类的方法
	public Double formatMethodByBigDecimal(Double value){
		return (new BigDecimal(value).setScale(2, RoundingMode.HALF_UP)).doubleValue();
	}
	
	// 通用的格式化方法,万能类型转换和格式化
	public Double formatMehtodByStringFormat(Double value){
		return Double.parseDouble(String.format("%1$.2f", value));
	}
	
	// 最专业格式化，还可以利用父类NumberFormat设置Locale
	public Double formatMehtodByDecimalFormat(Double value){
		return Double.parseDouble((new DecimalFormat("#0.00")).format(value));
	}
	
	// 针对百分比，但是需要按百分比里的数字排序而不是字典序
	public Double formatMethodBy(Double value){
		DecimalFormat df2 = (DecimalFormat)DecimalFormat.getPercentInstance();
		df2.setMaximumFractionDigits(2);
		return Double.parseDouble(df2.format(value));
	}
}
