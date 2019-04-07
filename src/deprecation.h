// Copyright (c) 2018 The Zelcash developers
// Copyright (c) 2017 The Zcash developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZELCASH_DEPRECATION_H
#define ZELCASH_DEPRECATION_H

// Deprecation policy:
// * Shut down 16 weeks' worth of blocks after the estimated release block height.
// * A warning is shown during the 2 weeks' worth of blocks prior to shut down.

static const int APPROX_RELEASE_HEIGHT = 350000;
static const int WEEKS_UNTIL_DEPRECATION = 26;
static const int DEPRECATION_HEIGHT = APPROX_RELEASE_HEIGHT + (WEEKS_UNTIL_DEPRECATION * 7 * 24 * 30);

// Number of blocks before deprecation to warn users
static const int DEPRECATION_WARN_LIMIT = 14 * 24 * 30; // 2 weeks

/**
 * Checks whether the node is deprecated based on the current block height, and
 * shuts down the node with an error if so (and deprecation is not disabled for
 * the current client version). Warning and error messages are sent to the debug
 * log, the metrics UI, and (if configured) -alertnofity.
 *
 * fThread means run -alertnotify in a free-running thread.
 */
void EnforceNodeDeprecation(int nHeight, bool forceLogging=false, bool fThread=true);

#endif // ZELCASH_DEPRECATION_H
