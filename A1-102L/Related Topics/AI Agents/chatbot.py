from crewai import Agent, Task, Crew
from langchain_openai import ChatOpenAI

import os
os.environ['OPENAI_API_KEY'] = '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'

llm = ChatOpenAI(model='gpt-4o-mini')

# 🎓 Career Coach
career_coach = Agent(
    role="Career Coach",
    goal="Suggest a modern and exciting career based on the user's interest",
    backstory="You're an expert in modern careers and love helping adults discover their future.",
    llm=llm
)

# 💡 Motivation Coach
motivation_coach = Agent(
    role="Motivation Coach",
    goal="Inspire the student with encouragement and a first action step",
    backstory="You're a high-energy motivator who pushes students to chase their dreams.",
    llm=llm
)

# 📚 Resource Finder
resource_finder = Agent(
    role="Learning Resource Expert",
    goal="Suggest 1-2 beginner-friendly resources to start learning about the career",
    backstory="You're a research genius who finds the best YouTube videos, blog posts, or courses.",
    llm=llm
)

# 🧠 Supervisor Agent
supervisor = Agent(
    role="Career Planning Supervisor",
    goal="Review the work of all agents and compile it into a complete final message for the student",
    backstory="You're the wise team leader who combines advice into a single, clear, helpful report.",
    llm=llm
)

interest = input("🎯 What are you interested in? ")

# Task 1 - Career suggestion
task1 = Task(
    description=f"Suggest a modern, exciting career for a teenager interested in '{interest}'. Give one reason why it fits.",
    expected_output="Career name and 1–2 lines of explanation.",
    agent=career_coach
)

# Task 2 - Motivation message
task2 = Task(
    description="Give a motivational quote or message and suggest a first small action step.",
    expected_output="1 quote/message + 1 action step.",
    agent=motivation_coach,
    depends_on=[task1]
)

# Task 3 - Learning resources
task3 = Task(
    description="Find 1–2 beginner-friendly resources (YouTube, blogs, courses) for the career suggested.",
    expected_output="List of 1–2 links or descriptions.",
    agent=resource_finder,
    depends_on=[task1]
)

# Task 4 - Supervisor final summary
task4 = Task(
    description="Take the output from all tasks and write a final message for the student with: career name, motivation, and resources.",
    expected_output="Final 5–6 line message with all outputs combined.",
    agent=supervisor,
    depends_on=[task1, task2, task3]
)

crew = Crew(
    agents=[career_coach, motivation_coach, resource_finder, supervisor],
    tasks=[task1, task2, task3, task4]
)

result = crew.kickoff()
print("🏁 Final AI Career Plan:\n")
print(result)



print("End Of Program!")