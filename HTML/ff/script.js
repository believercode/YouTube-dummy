// Sample player data
const playerStats = {
    name: "FF_Player_123",
    kills: 50,
    matchesPlayed: 120,
    headshots: 35
};

// Sample leaderboard data
const leaderboardData = [
    { name: "Player1", score: 1000 },
    { name: "Player2", score: 950 },
    { name: "Player3", score: 900 }
];

// Function to display player stats
function displayPlayerStats() {
    document.getElementById('player-name').textContent = playerStats.name;
    document.getElementById('kills').textContent = playerStats.kills;
    document.getElementById('matches').textContent = playerStats.matchesPlayed;
    document.getElementById('headshots').textContent = playerStats.headshots;
}

// Function to display leaderboard
function displayLeaderboard() {
    const leaderboardList = document.getElementById('leaderboard-list');
    leaderboardList.innerHTML = ''; // Clear the existing list
    leaderboardData.forEach(player => {
        const listItem = document.createElement('li');
        listItem.textContent = ${player.name}: ${player.score} points;
        leaderboardList.appendChild(listItem);
    });
}

// Run the functions to update the dashboard
displayPlayerStats();
displayLeaderboard();