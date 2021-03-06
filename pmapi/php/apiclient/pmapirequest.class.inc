<?php
/*
	class PMAPIRequest: represents a request (an RPC) to the PM PMAPI.

	Part of the Sign-Up.to Permission Marketing API v0.1 Redistributable


	Copyright (c) 2013 Sign-Up Technologies Ltd.
	All rights reserved.

	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions are met:

	1. Redistributions of source code must retain the above copyright notice, this
	   list of conditions and the following disclaimer.
	2. Redistributions in binary form must reproduce the above copyright notice,
	   this list of conditions and the following disclaimer in the documentation
	   and/or other materials provided with the distribution.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
	ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
	WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
	ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
	(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
	LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
	ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
	SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

require_once('pmapiauth.class.inc');
require_once('pmapiendpoint.class.inc');


class PMAPIRequest
{
	protected $Auth;
	protected $version;

	protected $server = 'api.sign-up.to';
	protected $debugMode = false;


	public function __construct(PMAPIAuth $Auth, $version = 1, $server = null, $debugMode = null)
	{
		$this->version = $version;	// will be validated in PMAPIEndpoint
		$this->Auth = $Auth;

		if(!is_null($server))
			$this->server = $server;

		if(!is_null($debugMode))
			$this->debugMode = (bool) $debugMode;
	}


	public function __get($endpoint)
	{
		return new PMAPIEndpoint($this->Auth, $this->server, $this->version, $endpoint,
									$this->debugMode);
	}
}

