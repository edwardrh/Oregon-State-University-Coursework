package Model;

import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by michaelhilton on 1/5/16.
 */
public class PersonTest {

    @Test
    public void testPersonName(){
        Person p = new Person();
        p.setName("Michael Hilton");
        assertEquals("Michael Hilton",p.getName());
    }


    @Test
    public void testGithubUserName(){
        Person p = new Person();
        p.setGithubUserName("MichaelHilton");
        assertEquals("MichaelHilton",p.getGithubUserName());
    }

    @Test
    public void testOS(){
        Person p = new Person();
        p.setOS("Mac");
        assertEquals("Mac",p.getOS());
    }


}