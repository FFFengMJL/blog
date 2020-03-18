如果由你来设计 Matrix API，目前有课程（course）、题目（problem）、提交（submission）、用户（user）四种元素/资源，请你为下列需求给出你认为合适的 API 设计（路径、请求方法）：（假定题目附属于课程，提交附属于题目）

1. 获取所有课程
```json
{
    "api_id" : 1,
    "name":"get all courses",
    "api" : "GET /course",
    "parameters" : {},
    "response content type" : "application/json",
    "response body": {
        "format" : 
        [
            {
                "course_id" : "number",
                "course_name" : "string",
                "teacher" : "string",
                "status" : "not_started / processing / ended",
                "link" : "url",
                "student_number" : "number",
                "identity" : "student / ta / teacher"
            },
            {},
            {}
        ],
        "example" : 
        [
            {
                "course_id" : 1,
                "course_name" : "c program language I",
                "teacher" : "Liu Cong",
                "status" : "processing",
                "link" : "https://vamtrix.org.cn/course/1",
                "student_number" : 1,
                "identity" : "teacher"
            },
            {},
            {}
        ],
    },
    "code" : {
        "200" : "OK",
        "403" : "Forbidden",
        "404" : "not found"
    }

}
```

2. 获取所有未结束的课程
```json
{
    "api_id" : 2,
    "name" : "get all courses which are not ended",
    "api" : "GET /course?status[]=not_started&status[]=processing",
    "parameters" : {},
    "response content type" : "application/json",
    "response body": {
        "format" : 
        [
            {
                "course_id" : "number",
                "course_name" : "string",
                "teacher" : "string",
                "status" : "not_started / processing",
                "link" : "url",
                "student_number" : "number",
                "identity" : "student / ta / teacher"
            },
            {},
            {}
        ],
        "example" : 
        [
            {
                "course_id" : 1,
                "course_name" : "c program language I",
                "teacher" : "Liu Cong",
                "status" : "processing",
                "link" : "https://vamtrix.org.cn/course/1",
                "student_number" : 1,
                "identity" : "teacher"
            },
            {},
            {}
        ],
    },
    "code" : {
        "200" : "OK",
        "403" : "Forbidden",
        "404" : "not found"
    },
    "备注" : "感觉 url 有点冗杂，可以考虑用 /course/status 配上 body 的参数表示"
},
{
    "api_id" : 2,
    "name" : "同上",
    "api" : "GET /course/status",
    "parameter" : {
        "body" : {
            "status" : [
                "not_started (optional)",
                "processing (optional)",
                "ended (optional)"
            ]
        }
    },
    "response content type" : "同上",
    "response body" : "同上",
    "code" : "同上",
    "备注" : "整体偏向于筛选课程用的 api"
},
{
    "api_id" : 2,
    "name" : "同上",
    "api" : "GET /course/not_ended",
    "parameter" : {},
    "response content type" : "同上",
    "response body" : "同上",
    "code" : "同上",
    "备注" : "很偷懒"
}
```

3. 创建课程
```json
{
    "api_id" : 3,
    "name" : "create a course",
    "api" : "POST /course/creation",
    "parameters" : {
        "format" : 
        {
            "course_name" : "string",
            "teacher" : "string",
            "start_time" : "string($date)",
            "end_time" : "string($date)",
            "description" : "string",
            "location" : "string",
        },
        "example" : 
        {
            "course_name" : "程序设计I",
            "teacher" : "刘聪",
            "start_time" : "2019-9-1",
            "end_time" : "2019-9-2",
            "description" : "年轻人的第一门编程",
            "location" : "家里"
        }

    },
    "response content type" : "application/json",
    "response body" : 
    {
        "format" : 
        {
            "course_id" : "number",
            "course_name" : "string",
            "teacher" : "string",
            "start_time" : "string($date)",
            "end_time" : "string($date)",
            "description" : "string",
            "location" : "string",
        },
        "example" : 
        {
            "body" : {
                "course_id" : 1,
                "course_name" : "程序设计I",
                "teacher" : "刘聪",
                "start_time" : "2019-9-1",
                "end_time" : "2019-9-2",
                "description" : "年轻人的第一门编程",
                "location" : "家里"
            }
        }
    },
    "code" : {
        "201" : "CREATED",
        "202" : "Accepted",
        "400" : "INVALID REQUEST",
        "403" : "Forbidden",
        "404" : "NOT FOUND（好像用不到）",
        "422" : "Unprocesable entity"
    }
}
```

4. 修改某个课程的信息

```json
{
    "api_id" : 4,
    "name" : "change the information of the course",
    "api" : "POST /course/change",
    "parameters" : {
        "format" : 
        {
            "course_id" : "number",
            "course_name" : "string",
            "teacher" : "string",
            "start_time" : "string($date)",
            "end_time" : "string($date)",
            "description" : "string",
            "location" : "string",
        },
        "example" : 
        {
            "course_id" : 1,
            "course_name" : "程序设计I",
            "teacher" : "刘聪",
            "start_time" : "2019-9-1",
            "end_time" : "2019-9-2",
            "description" : "年轻人的第一门编程",
            "location" : "家里"
        }

    },
    "response content type" : "application/json",
    "response body" : 
    {
        "format" : 
        {
            "course_id" : "number",
            "course_name" : "string",
            "teacher" : "string",
            "start_time" : "string($date)",
            "end_time" : "string($date)",
            "description" : "string",
            "location" : "string",
        },
        "example" : 
        {
            "body" : {
                "course_id" : 1,
                "course_name" : "程序设计I",
                "teacher" : "刘聪",
                "start_time" : "2019-9-1",
                "end_time" : "2019-9-2",
                "description" : "年轻人的第一门编程",
                "location" : "家里"
            }
        }
    },
    "code" : {
        "201" : "CREATED",
        "202" : "Accepted",
        "400" : "INVALID REQUEST",
        "403" : "Forbidden",
        "404" : "NOT FOUND"
    }
}
```

5. 获取某个课程的题目

```json
{
    "api_id" : "5",
    "name" : "get all problems in a course",
    "api" : "GET /course/${course_id}/problem",
    "parameters" : {
        "format" : {
            "course_id" : "number"
        },
        "example" : {
            "course_id" : 1
        }
    },
    "response content type" : "application/json",
    "response body" : {
        "format" : {
            "course_id" : "number",
            "problem" : [
                {
                    "problem_id" : "number",
                    "questioner" : "string",
                    "description" : "string"
                },
                {},
                {}
            ]
        },
        "example" : {
            "course_id" : 1,
            "problem" : [
                {
                    "problem_id" : 1,
                    "questioner" : "刘聪",
                    "description" : "没有描述哦"
                },
                {},
                {}
            ]
        }
    },
    "code" : {
        "200" : "OK",
        "401" : "Unauthorized",
        "404" : "NOT FOUND"
    }
}
```

6. 删除某个课程的某个题目

```json
{
    "api_id" : 6,
    "name" : "delete a problem in a course",
    "api" : "DELETE /course/${courde_id}/problem/${problem_id}",
    "parameters" : {
        "format" : {
            "course_id" : "number",
            "problem_id" : "number",
        },
        "example" : {
            "course_id" : 1,
            "problem_id" : 1
        }
    },
    "response content type" : "application/json",
    "response body" : {},
    "code" : {
        "204" : "NO CONTENT",
        "404" : "NOT FOUND",
        "403" : "Forbidden"
    }
}
```

7. 获取某个课程的某个题目的前 10 个提交

```json
{
    "api_id" : 7,
    "name" : "get the first 10 submissions of the problem in the course",
    "api" : "GET /course/${course_id}/problem/${problem_id}/submission?value=10",
    "parameter" : {
        "format" : {
            "course_id" : "number",
            "problem_id" : "number"
        },
        "example" : {
            "course_id" : 1,
            "problem_id" : 1
        }
    },
    "response content type" : "application/json",
    "response body" : {
        "format" : {
            "course_id" : "number",
            "problem_id" : "number",
            "submission" : [
                {
                    "submission_id" : "number",
                    "student_id" : "number",
                    "student_name" : "string",
                    "score" : "number"
                },
                {},
                {}
            ]
        },
        "example" : {
            "course_id" : 1,
            "problem_id" : 1,
            "submission" : [
                {
                    "submission_id" : 576,
                    "student_id" : 18342075,
                    "student_name" : "米家龙",
                    "score" : 0
                },
                {},
                {}
            ]
        }
    },
    "code" : {
        "200" : "OK",
        "404" : "NOT FOUND",
        "403" : "Forbidden"
    }
}
```

8. 创建某个课程的某个题目的提交

```json
{
    "api_id" : 8,
    "name" : "create a submission to the problem in the course",
    "api" : "POST /course/${course_id}/problem/${problem}/submission/creation",
    "parameter" : {
        "format" : {
            "course_id" : "number",
            "problem_id" : "number",
            "student_id" : "number",
        },
        "example" : {
            "course_id" : 1,
            "problem_id" : 1,
            "student_id" : 18342075
        }
    },
    "reponse content type" : "applicaiton/json",
    "reponse body" : {
        "format" : {
            "course_id" : "number",
            "problem_id" : "number",
            "student_id" : "number",
            "submission_id" : "number"
        },
        "example" : {
            "course_id" : 1,
            "problem_id" : 1,
            "student_id" : 1,
            "submission_id" : 1
        }
    },
    "code" : {
        "201" : "CREATED",
        "202" : "Accepted",
        "400" : "INVALID REQUEST",
        "403" : "Forbidden",
        "422" : "Unprocesable entity"
    }
}
```

9.  用户登录

```json
{
    "api_id" : 9,
    "name" : "user login",
    "api" : "POST /user/login",
    "parameter" : {
        "format" : {
            "username" : "string",
            "password" : "string"
        },
        "example" : {
            "username" : "matrix",
            "password" : "matrix13331314"
        }
    },
    "response content type" : "application/json",
    "response body" : {
        "format" : {
            "username" : "string"
        },
        "example" : {
            "username" : "matrix"
        }
    },
    "code" : {
        "200" : "OK",
        "202" : "ACCEPT",
        "401" : "Unauthorized"
    }
}
```