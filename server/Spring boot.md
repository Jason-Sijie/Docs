# Spring boot

## Restful

### Set up

1. Spring initial a project with gradle
2. copy the gradle.build from the [Guide](https://spring.io/guides)

3. Intellij IDE (need Ultimate)
    1. Add Spring framework
    2. import the gradle config
    3. check all the needed classpaths are added
    4. `./gradlew build` && `java -jar build/lib/...`

### Annotation

#### Request

- @RequestMapping
    1. place annotation at the front of the method. defaultly maps all HTTP requests 'GET, PUT, POST'. 
    2. `@RequestMapping(method==GET)` to restrict the type

- @RequestParam
    1. bind query string parameter into method local variable. 
    ```Java
    public Greeting greeting(@RequestParam(value = "name", defaultValue="World") String varName) {
        return varName;
    }
    ```

- @RequestBody
    - For post request, it automatically parse the JSON into Java object.


- Return value
    1. If you return an object, the object would be automatically written to the HTTP response as JSON, by **Jaskson 2**

- @RestController
    1. place it at the front of the class, mark the class as a controller. **All its methods return a domain object instead of a view** (TODO: What is a domain object?)
    2. It's shorthand for @Controller and @ResponseBody

#### Application

1. @SpringBootApplication
    1. It's the combination of @Configuration @EnableAutoConfiguration @ComponentScan
    2. you use Spring’s support for embedding the Tomcat servlet container as the HTTP runtime, instead of deploying to an external instance.

2. @ComponentScan
    - We can set the root package for component scan: `@ComponentScan(basePackages = <root package>)`

#### Scheduled Task

[Link to Spring boot guide](https://spring.io/guides/gs/scheduling-tasks/)


### Database

#### Install Mysql on Docker

[Link to Docker hub](https://hub.docker.com/_/mysql/)

1. install mysql image
    ```s
    sudo docker run --rm \
   -v /tmp/test1:/var/lib/mysql \
   --name mysql01 \
   -e MYSQL_ROOT_PASSWORD=root \
   -e MYSQL_ROOT_HOST='%' \
   -p 3306:3306 \
   -d \
   mysql:latest
    ```
    1. -v overwrite the path we store the data in container. For example, we can store the containers' data on local host.
    2. -p "local_port : container_port"

2. connect to mysql server from client
    1. start another image with a Mysql client connecting to the created Mysql server
    2. `docker run -it --network chattime-mysql --rm mysql mysql -hsome-mysql -uexample-user -p`

3. container shell access
    1. `docker exec -it some-mysql bash`

4. docker hostname and port
    1. get ip address of the container `ip a | grep docker | grep inet`
    2. map port to container
        1. when creating: `docker run -it --name <name> -p local_port:docker_port`
        2. after creation: [link](https://forums.docker.com/t/solved-edit-container-details-ports-and-restarts-etc/64699)
            1. check container hashid `sudo docker inspect <container name>`
            2. stop container and docker `sudo docker stop <name> && sudo systemctl stop docker`
            3. change the file `/var/lib/docker/containers/hash_id/hostconfig.json`
            ```json
            "PortBindings": {
                "3306/tcp": [
                    {
                        "HostIp": "",
                        "HostPort": "23306"
                    }
                ],
            }
            ```
            4. restart docker and container


#### Access Data with MySQL

[Guide](https://spring.io/guides/gs/accessing-data-mysql/)

1. TODO: why must Repository and Applicaiton under the same directory?

2. Update `application.properties`
```s
spring.jpa.hibernate.ddl-auto=update
spring.datasource.url=jdbc:mysql://<your docker mysql ip addr>:3306/db_example
spring.datasource.username=springuser
spring.datasource.password=ThePassword
```


### Test

#### Junit

- Annotation
    - @Test : add before each test case
    - @RunWith(SpringRunner.class) : add before the test class

- Logger
    - import `org.slf4j.Logger` and `org.slf4j.LoggerFactory`
    - `static final Logger logger = LoggerFactory.getLogger`
    - the test log file is in the build/test-results

#### Http Request

- Real start the server
    - Port
        - `@SpringBootTest(webEnvironment = SpringBootTest.WebEnvironment.RANDOM_PORT)` 
            - start the test with random port, avoid conflicts
        - `@LocalServerPort private int port`
    - TestRestTemplate
        - can consturct with credentials `new TestRestTemplate("user", "password")`

         
- Mock MVC
    - @AutoConfigureMockMvc: add before test class, it would load the full application context but without server.
    - `@Autowired private MockMvc`

- @WebMvcTest
    - @WebMvcTest: add before test class, it would only load the web layer.
    - `@WebMvcTest(xxx.class)`: only load the specific controller


## Security

## Web Socket

### STOMP (Streming Text Oriented Messaging Protocol)

- Message handling controller
    - `@MessageMapping("/hello")`: process messages sent to "/hello"
    - `@SendTo("url")`: broadcast return value to all subscribers to that url

- Configuration class
    - TODO: what's the exact workflow of the `MessageBroker`?