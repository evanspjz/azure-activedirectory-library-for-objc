// Copyright (c) Microsoft Corporation.
// All rights reserved.
//
// This code is licensed under the MIT License.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import "ADTokenCacheAccessor.h"

@interface ADAuthenticationRequest (TokenCaching)

+ (NSString*)fociClientId:(NSString*)familyID;

/*!
    Stores the result in the cache. cacheItem parameter may be nil, if the result is successfull and contains
    the item to be stored.
 
    @param result       The result to update the cache to
    @param refreshToken The refresh token (if anything) that was used to get this authentication result
 */
- (void)updateCacheToResult:(ADAuthenticationResult *)result
                  cacheItem:(ADTokenCacheItem *)cacheItem
               refreshToken:(NSString *)refreshToken;


- (ADTokenCacheItem *)getItemForResource:(NSString*)resource
                                clientId:(NSString*)clientId
                                   error:(ADAuthenticationError * __autoreleasing *)error;

- (ADTokenCacheItem*)getUnkownUserADFSToken:(ADAuthenticationError * __autoreleasing *)error;

@end
