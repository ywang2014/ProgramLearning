package Day1;

import org.junit.Test;
import org.junit.Assert;

import junit.framework.TestCase;

public class JunitTest extends TestCase
{
	@Test
	public void testPrime()
	{
		Assert.assertEquals(Factors.prime(2), true);
	}
}
