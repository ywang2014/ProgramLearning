/**
	http://blog.csdn.net/kkkkkxiaofei/article/details/7904569
*/
private void button1_Click(object sender, EventArgs e){
	string con, sql;
	con = "Server=.;Database=Exercise;Trusted_Connection=SSPI"; 
	sql = "select * from lianxi"; 
	SqlConnection mycon = new SqlConnection(con); 
	mycon.Open();
	SqlDataAdapter myda = new SqlDataAdapter(sql, con);
	DataSet myds = new DataSet(); 
	myda.Fill(myds, "lianxi");
	dataGridView1.DataSource = myds.Tables["lianxi"];
	mycon.Close();  
}