/// <reference path="../../typings/tsd.d.ts" />

import * as request from "superagent";
import {
    SuperAgentStatic
} from "superagent";

type CallbackHandler = (err: any, res ? : request.Response) => void;
type sphere = {
    'name' ? : string

    'level' ? : string

};
type competence = {
    'name' ? : string

};
type competenceId = {
    'name' ? : string

    'passed' ? : number

    'value' ? : number

};
type courses = {
    'name' ? : string

    'price' ? : number

};
type courseId = {
    'name' ? : string

    'price' ? : number

    'image' ? : string

};
type Error = {
    'message': string

};

type Logger = {
    log: (line: string) => any
};

/**
 * 
 * @class ProductService
 * @param {(string)} [domainOrOptions] - The project domain.
 */
export default class ProductService {

    private domain: string = "http://localhost:10010/api/v1";
    private errorHandlers: CallbackHandler[] = [];

    constructor(domain ? : string, private logger ? : Logger) {
        if (domain) {
            this.domain = domain;
        }
    }

    getDomain() {
        return this.domain;
    }

    addErrorHandler(handler: CallbackHandler) {
        this.errorHandlers.push(handler);
    }

    private request(method: string, url: string, body: any, headers: any, queryParameters: any, form: any, reject: CallbackHandler, resolve: CallbackHandler) {
        if (this.logger) {
            this.logger.log(`Call ${method} ${url}`);
        }

        let req = (request as SuperAgentStatic)(method, url).query(queryParameters);

        Object.keys(headers).forEach(key => {
            req.set(key, headers[key]);
        });

        if (body) {
            req.send(body);
        }

        if (typeof(body) === 'object' && !(body.constructor.name === 'Buffer')) {
            req.set('Content-Type', 'application/json');
        }

        if (Object.keys(form).length > 0) {
            req.type('form');
            req.send(form);
        }

        req.end((error, response) => {
            if (error || !response.ok) {
                reject(error);
                this.errorHandlers.forEach(handler => handler(error));
            } else {
                resolve(response);
            }
        });
    }

    getSphereURL(parameters: {
        'name' ? : string,
        'level' ? : string,
        $queryParameters ? : any,
        $domain ? : string
    }): string {
        let queryParameters: any = {};
        const domain = parameters.$domain ? parameters.$domain : this.domain;
        let path = '/sphere';
        if (parameters['name'] !== undefined) {
            queryParameters['name'] = parameters['name'];
        }

        if (parameters['level'] !== undefined) {
            queryParameters['level'] = parameters['level'];
        }

        if (parameters.$queryParameters) {
            Object.keys(parameters.$queryParameters).forEach(function(parameterName) {
                queryParameters[parameterName] = parameters.$queryParameters[parameterName];
            });
        }

        let keys = Object.keys(queryParameters);
        return domain + path + (keys.length > 0 ? '?' + (keys.map(key => key + '=' + encodeURIComponent(queryParameters[key])).join('&')) : '');
    }

    /**
     * Provide list of sphere, filtered out by brand or nationwide. The list support paging
     * @method
     * @name ProductService#getSphere
     * @param {string} name - 
     * @param {string} level - 
     */
    getSphere(parameters: {
        'name' ? : string,
        'level' ? : string,
        $queryParameters ? : any,
        $domain ? : string
    }): Promise < request.Response > {
        const domain = parameters.$domain ? parameters.$domain : this.domain;
        let path = '/sphere';
        let body: any;
        let queryParameters: any = {};
        let headers: any = {};
        let form: any = {};
        return new Promise((resolve, reject) => {
            headers['Accept'] = 'application/json';
            headers['Content-Type'] = 'application/json';

            if (parameters['name'] !== undefined) {
                queryParameters['name'] = parameters['name'];
            }

            if (parameters['level'] !== undefined) {
                queryParameters['level'] = parameters['level'];
            }

            if (parameters.$queryParameters) {
                Object.keys(parameters.$queryParameters).forEach(function(parameterName) {
                    queryParameters[parameterName] = parameters.$queryParameters[parameterName];
                });
            }

            this.request('GET', domain + path, body, headers, queryParameters, form, reject, resolve);
        });
    }

    getСompetenceURL(parameters: {
        'cProgrammer' ? : string,
        'webDesigner' ? : string,
        'interiorDesigner' ? : string,
        'mobileApplicationDeveloper' ? : string,
        $queryParameters ? : any,
        $domain ? : string
    }): string {
        let queryParameters: any = {};
        const domain = parameters.$domain ? parameters.$domain : this.domain;
        let path = '/sphere/competence';
        if (parameters['cProgrammer'] !== undefined) {
            queryParameters['C++ programmer'] = parameters['cProgrammer'];
        }

        if (parameters['webDesigner'] !== undefined) {
            queryParameters['Web Designer'] = parameters['webDesigner'];
        }

        if (parameters['interiorDesigner'] !== undefined) {
            queryParameters['Interior designer'] = parameters['interiorDesigner'];
        }

        if (parameters['mobileApplicationDeveloper'] !== undefined) {
            queryParameters['Mobile Application Developer'] = parameters['mobileApplicationDeveloper'];
        }

        if (parameters.$queryParameters) {
            Object.keys(parameters.$queryParameters).forEach(function(parameterName) {
                queryParameters[parameterName] = parameters.$queryParameters[parameterName];
            });
        }

        let keys = Object.keys(queryParameters);
        return domain + path + (keys.length > 0 ? '?' + (keys.map(key => key + '=' + encodeURIComponent(queryParameters[key])).join('&')) : '');
    }

    /**
     * Provide list of competence, filtered out by brand or nationwide. The list support paging
     * @method
     * @name ProductService#getСompetence
     * @param {string} cProgrammer - The name of the competence
     * @param {string} webDesigner - The name of the competence
     * @param {string} interiorDesigner - The name of the competence
     * @param {string} mobileApplicationDeveloper - The name of the competence
     */
    getСompetence(parameters: {
        'cProgrammer' ? : string,
        'webDesigner' ? : string,
        'interiorDesigner' ? : string,
        'mobileApplicationDeveloper' ? : string,
        $queryParameters ? : any,
        $domain ? : string
    }): Promise < request.Response > {
        const domain = parameters.$domain ? parameters.$domain : this.domain;
        let path = '/sphere/competence';
        let body: any;
        let queryParameters: any = {};
        let headers: any = {};
        let form: any = {};
        return new Promise((resolve, reject) => {
            headers['Accept'] = 'application/json';
            headers['Content-Type'] = 'application/json';

            if (parameters['cProgrammer'] !== undefined) {
                queryParameters['C++ programmer'] = parameters['cProgrammer'];
            }

            if (parameters['webDesigner'] !== undefined) {
                queryParameters['Web Designer'] = parameters['webDesigner'];
            }

            if (parameters['interiorDesigner'] !== undefined) {
                queryParameters['Interior designer'] = parameters['interiorDesigner'];
            }

            if (parameters['mobileApplicationDeveloper'] !== undefined) {
                queryParameters['Mobile Application Developer'] = parameters['mobileApplicationDeveloper'];
            }

            if (parameters.$queryParameters) {
                Object.keys(parameters.$queryParameters).forEach(function(parameterName) {
                    queryParameters[parameterName] = parameters.$queryParameters[parameterName];
                });
            }

            this.request('GET', domain + path, body, headers, queryParameters, form, reject, resolve);
        });
    }

    getCompetenceURL(parameters: {
        'competenceId': string,
        'name' ? : string,
        'passed' ? : string,
        'value' ? : number,
        $queryParameters ? : any,
        $domain ? : string
    }): string {
        let queryParameters: any = {};
        const domain = parameters.$domain ? parameters.$domain : this.domain;
        let path = '/sphere/compentence/{competenceId}';

        path = path.replace('{competenceId}', `${parameters['competenceId']}`);
        if (parameters['name'] !== undefined) {
            queryParameters['name'] = parameters['name'];
        }

        if (parameters['passed'] !== undefined) {
            queryParameters['passed'] = parameters['passed'];
        }

        if (parameters['value'] !== undefined) {
            queryParameters['value'] = parameters['value'];
        }

        if (parameters.$queryParameters) {
            Object.keys(parameters.$queryParameters).forEach(function(parameterName) {
                queryParameters[parameterName] = parameters.$queryParameters[parameterName];
            });
        }

        let keys = Object.keys(queryParameters);
        return domain + path + (keys.length > 0 ? '?' + (keys.map(key => key + '=' + encodeURIComponent(queryParameters[key])).join('&')) : '');
    }

    /**
     * Returns the simple competence for its ID
     * @method
     * @name ProductService#getCompetence
     * @param {string} competenceId - id of competence
     * @param {string} name - Name of competence
     * @param {string} passed - passed or not
     * @param {number} value - how many passed
     */
    getCompetence(parameters: {
        'competenceId': string,
        'name' ? : string,
        'passed' ? : string,
        'value' ? : number,
        $queryParameters ? : any,
        $domain ? : string
    }): Promise < request.Response > {
        const domain = parameters.$domain ? parameters.$domain : this.domain;
        let path = '/sphere/compentence/{competenceId}';
        let body: any;
        let queryParameters: any = {};
        let headers: any = {};
        let form: any = {};
        return new Promise((resolve, reject) => {
            headers['Accept'] = 'application/json';
            headers['Content-Type'] = 'application/json';

            path = path.replace('{competenceId}', `${parameters['competenceId']}`);

            if (parameters['competenceId'] === undefined) {
                reject(new Error('Missing required  parameter: competenceId'));
                return;
            }

            if (parameters['name'] !== undefined) {
                queryParameters['name'] = parameters['name'];
            }

            if (parameters['passed'] !== undefined) {
                queryParameters['passed'] = parameters['passed'];
            }

            if (parameters['value'] !== undefined) {
                queryParameters['value'] = parameters['value'];
            }

            if (parameters.$queryParameters) {
                Object.keys(parameters.$queryParameters).forEach(function(parameterName) {
                    queryParameters[parameterName] = parameters.$queryParameters[parameterName];
                });
            }

            this.request('GET', domain + path, body, headers, queryParameters, form, reject, resolve);
        });
    }

    getCoursesURL(parameters: {
        'competenceId': string,
        'name' ? : string,
        'price' ? : number,
        $queryParameters ? : any,
        $domain ? : string
    }): string {
        let queryParameters: any = {};
        const domain = parameters.$domain ? parameters.$domain : this.domain;
        let path = '/sphere/competence/{competenceId}/courses';

        path = path.replace('{competenceId}', `${parameters['competenceId']}`);
        if (parameters['name'] !== undefined) {
            queryParameters['name'] = parameters['name'];
        }

        if (parameters['price'] !== undefined) {
            queryParameters['price'] = parameters['price'];
        }

        if (parameters.$queryParameters) {
            Object.keys(parameters.$queryParameters).forEach(function(parameterName) {
                queryParameters[parameterName] = parameters.$queryParameters[parameterName];
            });
        }

        let keys = Object.keys(queryParameters);
        return domain + path + (keys.length > 0 ? '?' + (keys.map(key => key + '=' + encodeURIComponent(queryParameters[key])).join('&')) : '');
    }

    /**
     * Provide list of sphere, filtered out by brand or nationwide. The list support paging
     * @method
     * @name ProductService#getCourses
     * @param {string} competenceId - id of competence
     * @param {string} name - Name of competence
     * @param {number} price - price
     */
    getCourses(parameters: {
        'competenceId': string,
        'name' ? : string,
        'price' ? : number,
        $queryParameters ? : any,
        $domain ? : string
    }): Promise < request.Response > {
        const domain = parameters.$domain ? parameters.$domain : this.domain;
        let path = '/sphere/competence/{competenceId}/courses';
        let body: any;
        let queryParameters: any = {};
        let headers: any = {};
        let form: any = {};
        return new Promise((resolve, reject) => {
            headers['Accept'] = 'application/json';
            headers['Content-Type'] = 'application/json';

            path = path.replace('{competenceId}', `${parameters['competenceId']}`);

            if (parameters['competenceId'] === undefined) {
                reject(new Error('Missing required  parameter: competenceId'));
                return;
            }

            if (parameters['name'] !== undefined) {
                queryParameters['name'] = parameters['name'];
            }

            if (parameters['price'] !== undefined) {
                queryParameters['price'] = parameters['price'];
            }

            if (parameters.$queryParameters) {
                Object.keys(parameters.$queryParameters).forEach(function(parameterName) {
                    queryParameters[parameterName] = parameters.$queryParameters[parameterName];
                });
            }

            this.request('GET', domain + path, body, headers, queryParameters, form, reject, resolve);
        });
    }

    getCourseURL(parameters: {
        'competenceId': string,
        'courseId': string,
        'name' ? : string,
        'img' ? : string,
        'price' ? : number,
        $queryParameters ? : any,
        $domain ? : string
    }): string {
        let queryParameters: any = {};
        const domain = parameters.$domain ? parameters.$domain : this.domain;
        let path = '/sphere/compentence/{competenceId}/courses/{courseId}';

        path = path.replace('{competenceId}', `${parameters['competenceId']}`);

        path = path.replace('{courseId}', `${parameters['courseId']}`);
        if (parameters['name'] !== undefined) {
            queryParameters['name'] = parameters['name'];
        }

        if (parameters['img'] !== undefined) {
            queryParameters['img'] = parameters['img'];
        }

        if (parameters['price'] !== undefined) {
            queryParameters['price'] = parameters['price'];
        }

        if (parameters.$queryParameters) {
            Object.keys(parameters.$queryParameters).forEach(function(parameterName) {
                queryParameters[parameterName] = parameters.$queryParameters[parameterName];
            });
        }

        let keys = Object.keys(queryParameters);
        return domain + path + (keys.length > 0 ? '?' + (keys.map(key => key + '=' + encodeURIComponent(queryParameters[key])).join('&')) : '');
    }

    /**
     * Returns the simple course for its ID
     * @method
     * @name ProductService#getCourse
     * @param {string} competenceId - The competence id
     * @param {string} courseId - The course id
     * @param {string} name - Name of course id
     * @param {string} img - Image URL
     * @param {number} price - price
     */
    getCourse(parameters: {
        'competenceId': string,
        'courseId': string,
        'name' ? : string,
        'img' ? : string,
        'price' ? : number,
        $queryParameters ? : any,
        $domain ? : string
    }): Promise < request.Response > {
        const domain = parameters.$domain ? parameters.$domain : this.domain;
        let path = '/sphere/compentence/{competenceId}/courses/{courseId}';
        let body: any;
        let queryParameters: any = {};
        let headers: any = {};
        let form: any = {};
        return new Promise((resolve, reject) => {
            headers['Accept'] = 'application/json';
            headers['Content-Type'] = 'application/json';

            path = path.replace('{competenceId}', `${parameters['competenceId']}`);

            if (parameters['competenceId'] === undefined) {
                reject(new Error('Missing required  parameter: competenceId'));
                return;
            }

            path = path.replace('{courseId}', `${parameters['courseId']}`);

            if (parameters['courseId'] === undefined) {
                reject(new Error('Missing required  parameter: courseId'));
                return;
            }

            if (parameters['name'] !== undefined) {
                queryParameters['name'] = parameters['name'];
            }

            if (parameters['img'] !== undefined) {
                queryParameters['img'] = parameters['img'];
            }

            if (parameters['price'] !== undefined) {
                queryParameters['price'] = parameters['price'];
            }

            if (parameters.$queryParameters) {
                Object.keys(parameters.$queryParameters).forEach(function(parameterName) {
                    queryParameters[parameterName] = parameters.$queryParameters[parameterName];
                });
            }

            this.request('GET', domain + path, body, headers, queryParameters, form, reject, resolve);
        });
    }

}
