const list = document.getElementById("list");
const task = document.getElementById("task");
const btn = document.getElementById("btn");

const tasks = [];

btn.addEventListener("click", (e) => {
  e.preventDefault();
  const taskValue = task.value;
  task.value = "";
  if (taskValue) {
    tasks.push(taskValue);
    list.innerHTML = "";
    for (const task of tasks) {
      const li = document.createElement("li");
      li.innerHTML = `
        <input type="checkbox">
        <span>${task}</span>
      `;
      li.querySelector("input").addEventListener("click", (e) => {
        li.style.textDecoration = e.target.checked ? "line-through" : "none";
        e.target.disabled = true;
      });
      list.appendChild(li);
    }
  }
});
